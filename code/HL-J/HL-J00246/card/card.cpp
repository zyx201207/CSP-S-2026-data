#include<bits/stdc++.h>
using namespace std;
int a[5010],f[5010];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]+=1;
			}
			else{
				for(int j=1;j<=n;j++){
					f[j]=0;

				}
				f[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
