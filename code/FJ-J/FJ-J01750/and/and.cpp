#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,a[N];
ll cmp(ll a,ll b){return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		ll mx=-1;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx<<"\n";
		return 0;
	}
	if(m==n){
		ll res=a[1];
		for(int i=2;i<=n;i++) res=res&a[i];
		cout<<res<<"\n";
		return 0;
	}
	if(m==n-1){
		ll mn=N,x=0;
		for(int i=1;i<=n;i++){if(mn>a[i]){mn=a[i];x=i;}}
		ll res=(x==1)?a[2]:a[1];
		for(int i=(x==1)?3:2;i<=n&&i!=x;i++) res=res&a[i];
		cout<<res<<"\n";
		return 0;
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if((a[i]&(a[i]+1))!=0) flag=false;
	}
	if(flag=true){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	if(m==2){
		ll mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&j!=i;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx<<"\n";
		return 0;
	}
	bool fg=true;
	for(int i=1;i<=n;i++){
		if((a[i]!=i-1) flag=false;
	}
	if(n&(n-1)==0&&fg){
		sort(a+1,a+n+1,cmp);
		ll res=a[1];
		for(int i=1;i<=m;i++){
			res=res&a[i];
		}
		cout<<res<<"\n";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*created by luve on 2026/10/31 10:38 40pts(?*/
