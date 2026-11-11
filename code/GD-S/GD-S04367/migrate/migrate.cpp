#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n;ll d;
ll a[N];
void specialA(){
	ll T=a[2]-a[1];
	cout<<T<<' ';
	if(d<T*2) cout<<"0\n";//cannot fly 2ge
	else{
		ll *f=lower_bound(a+1,a+1+n,a[1]+d*2);
		int len=f-(a+1);
		if((*f)==a[1]+d*2){
			len--;
		}
		else len-=2;
		cout<<n/len<<'\n'; 
	} 
} 
void sol(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int nct=0;
			for(int k=i+1;k<j;k++){
				if(abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d) nct++;
			}
			if(nct==2) cnt++;
		}
	}
	cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;int c;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sol();
	}
	return 0;
}
