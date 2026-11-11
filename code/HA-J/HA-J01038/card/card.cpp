#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005];
bool b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				for(int l=1;l<=n;l++){
					if(a[l]==a[j]){
						//cout<<'c'<<a[l]<<" "<<a[j]<<endl;
						for(int p=l;p<=j-1;p++){
							if(a[p]!=a[l]) b[a[p]]=0;
						}
						break;
					}
				}
			}
			b[a[j]]=1;
			//for(int l=1;l<=m;l++) cout<<b[l]<<" ";
			//cout<<endl;
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1) ans[j]++;
		}//cout<<endl;
	}for(int i=1;i<=m;i++) cout<<ans[i]<<" "; 
	return 0;
}
