#include <bits/stdc++.h>
using namespace std; 
int n,m;
int a[500000],s[500000];
int sum[300000],maxx[300000];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s[a[i]]=i-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) sum[j]=0;
		for(int j=i;j<=n;j++){
             if(sum[a[j]]!=0) 
             {
             	for(int k=1;k<=m;k++)
             	{
             		if(k!=a[j]) sum[k]=0;
				 }
			 }
             else sum[a[j]]++;
		}
		for(int j=1;j<=m;j++) maxx[j]+=sum[j];
	}
	for(int i=1;i<=m;i++) cout<<maxx[i]<<" ";
	return 0;
}
