#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ne[N],last[M],ans[M],f[M],f1[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		ne[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		f[a[i]]++;
		if(f[a[i]]==1)f1[a[i]]=i;
		if(ne[i]!=0){
			for(int j=i;j<ne[i];j++){
				f[a[j]]--;
				if(f[a[j]]==0){
					ans[a[j]]+=f1[a[j]]-i;
					f1[a[j]]=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]+f1[i]<<" ";
	return 0;
} 
