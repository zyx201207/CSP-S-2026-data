#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=500005;
int n,ans=1,p=1;ll m;
ll a[MAXN],Q[MAXN]; 
inline bool Check(int l,int r){
	ll S1=Q[r]-Q[l-1];
	ll S2=1ll*(r-l+1)*a[r];
	if(S2-S1<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)Q[i]=Q[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(!Check(p,i))p++;
		ans=max(ans,i-p+1);
	}printf("%d",ans);
	return 0;
}
