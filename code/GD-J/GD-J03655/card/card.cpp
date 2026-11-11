#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],c[300001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[j]==a[l] and b[l]==0){
					for(int k=j;k<l;k++){
						b[k]=1;
					}j=l-1;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]==0 and c[a[j]]==0){
				ans[a[j]]++;
				c[a[j]]++;
			}
		}memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
