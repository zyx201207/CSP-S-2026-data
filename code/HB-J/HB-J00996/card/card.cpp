#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[5000100],vis[5000100],a1[5000100],op[5000100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		if(vis[a[j]]!=0){
			for(int k=vis[a[j]];k<j;k++){
				vis[a1[k]]=0;
				a1[k]=0;
			}
		}
		a1[j]=a[j];
		vis[a1[j]]=j;
	}
	for(int j=i;j<=n;j++){
		if(a1[j]!=0){
			op[a1[j]]++;
		}
	}
	for(int j=1;j<=n;j++){
		a1[j]=0;
		vis[j]=0;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<op[i]<<" ";
	}
	
	return 0;
}
