#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50001];
	int sum[30001]={};
	int righ[30001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		righ[a[i]]=i;
	}for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j=righ[a[j]]+1){
			sum[a[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
} 
