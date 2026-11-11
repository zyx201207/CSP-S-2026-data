#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],be[N],ed[N],ans[N];
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(be,0,sizeof be);
		memset(ed,0,sizeof ed);
		for(int j=i;j<=n;j++){
			ed[a[j]]=j;
			if(be[a[j]]){
				for(int k=be[a[j]];k<ed[a[j]];k++){
					if(be[a[k]]==k) be[a[k]]=0;
				}
			}
			be[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(be[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
