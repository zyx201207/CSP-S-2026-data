#include<bits/stdc++.h>
#define ll long long
using namespace  std;
const int N=5e5+7;
ll n,m;
ll a[N],q[N];
ll sum,cnt=2;
bool f=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i+=cnt,cnt++){
		for(int j=i;j<=i+cnt-1;j++){
			q[j]=cnt;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			f=1;
		}else f=0;
	}
	if(f==1){
		cout<<q[m];
	}else{
		if(m/a[1]==1) cout<<m/a[1]+1;
		else cout<<m/a[1];
	} 
	return 0;
} 
