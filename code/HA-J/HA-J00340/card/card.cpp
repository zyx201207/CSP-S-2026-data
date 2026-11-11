#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],ans[300010];
bool b[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		memset(b,1,sizeof(b));
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]&&b[k]==1&&b[j]==1){
					for(int x=k;x<j;x++){
						b[x]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]){
				ans[a[j]]++;
				b[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
