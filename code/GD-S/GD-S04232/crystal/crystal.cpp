#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],f[500005];
bool check(ll x){
if(f[x]==-1){
	for(int i=x-1;i>=1;i--){
		if(f[i]!=-1){
		f[x]+=f[i];
		f[x]+=abs(a[x]-a[i])*i;
			break;
		}
		else f[x]+=abs(a[x]-a[i]);
	}
}return f[x]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];f[i]=-1;
	}sort(a+1,a+1+n);
	ll l=0,r=n+1,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}else r=mid;
	}cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
} //Oct31==Dec25?
