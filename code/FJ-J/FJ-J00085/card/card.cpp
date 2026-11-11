#include <bits/stdc++.h>
using namespace std;
int ans[3005];
int a[5005];
int n, m;
int c[3005];
int v[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt=0;
		memset(c,0,sizeof(c));
	    memset(v,0,sizeof(v));
		for(int j=i;j<=n;++j){
			if(v[a[j]]==0){
				++cnt;
				c[cnt]=a[j];
				v[a[j]]=cnt;
			}
			else{
				for(int k=v[a[j]]+1;k<=cnt;++k){
					v[c[k]]=0;
				}
				cnt=v[a[j]];
			}
		}
		for(int j=1;j<=cnt;++j){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
}

