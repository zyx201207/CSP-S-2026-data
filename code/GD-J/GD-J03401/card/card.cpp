#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],t[300005],pi[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i<=m) t[i]=0;
			pi[i]=0;
		}
		for(int i=k;i<=n;i++){
			b[i]=a[i];
			if(t[b[i]]==1){
				for(int j=pi[b[i]];j<i;j++){
					t[b[j]]=0;
					pi[b[j]]=0;
				}
			}
			t[b[i]]=1;
			pi[b[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(t[i]==1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]!=0) cout<<ans[i]<<" ";
	}
	return 0;
} 
