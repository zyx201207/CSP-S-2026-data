#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],p[500005],f[500005],top,g[500005];
bool s[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int pp=1;
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		top=0;
		for(int j=i;j<=n;j++){
			f[++top]=a[j];
			if(p[a[j]]!=0){
				top=p[a[j]];
			}else{
				p[a[j]]=pp;
			}
			pp++;
		}
		for(int j=1;j<=top;j++){
			s[f[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(s[j]){
				g[j]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<g[j]<<" ";
	}
	return 0;
} 
