#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],c[300010],mx[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool d[500010]={};
		bool b[300010]={};
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1&&d[mx[a[j]]]==0){
				for(int x=j-1;x>=mx[a[j]];x--){
					d[x]=1;
				}
				mx[a[j]]=j;
			}
			else{
				b[a[j]]=1;
				mx[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(d[j]==0)
				c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
