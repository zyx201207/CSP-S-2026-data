#include<bits/stdc++.h>
using namespace std;
#define _for(i,x,y,z) for(int i=x;i<=y;i+=z)
typedef long long ll;
const int N=6e5+5;
int s[N],jz[N];
int n,m;
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	_for(i,1,n,1){
		cin>>s[i];
		jz[s[i]]=max(jz[s[i]],i);
	}_for(i,1,n,1){
		int f[N],a[N],sz=0;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		_for(j,max(i,jz[s[i]]),n,1){
			int x=s[j];
			if(a[x]){
				_for(k,a[x]+1,sz,1)a[f[k]]=0;
				sz=a[x]-1;
			}f[++sz]=x;
			a[x]=sz;
		}_for(j,1,sz,1)ans[f[j]]++;
	}_for(i,1,m,1)cout<<ans[i]<<" ";
}
