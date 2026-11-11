#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string a[200005],b[200005];
ll ans,p;
void to2(int k,int x){
	string s;
	while(x){
		s+='0'+x%2;
		x/=2;
	}
	int len=s.size();
	for(int i=len;i<=40;i++){
		s+='0';
	}
	for(int i=35;i>=0;i--){
		a[k]+=s[i];
	}
}
ll cf2(ll x,ll y){
	ll ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		to2(i,x);
	}
	int w=n;
	p=cf2(2,35);
	for(int i=0;i<=35;i++){
		int cnt=0;
		for(int j=1;j<=w;j++){
			if(a[j][i]=='1'){
				cnt++;
			}
		}
		int t=0;
		if(cnt>=m){
			for(int j=1;j<=w;j++){
				if(a[j][i]=='1'){
					a[++t]=a[j];
				}
			}
			
			w=cnt;
			ans+=p;
		}
		p/=2;
	}
	cout<<ans;
    return 0;
}
