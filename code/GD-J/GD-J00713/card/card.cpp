#include<bits/stdc++.h>
using namespace std;
int a[100000],tong[1000000],ok[1000000],tong1[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			tong[a[j]]++;
			if(tong[a[j]]>1){
				tong[a[j]]=0;
				for(int k=j;a[k]==a[j]&&k!=j;k--){
					ok[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(ok[j]==0)tong1[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<tong1[i]<<" ";
	return 0;
} 
