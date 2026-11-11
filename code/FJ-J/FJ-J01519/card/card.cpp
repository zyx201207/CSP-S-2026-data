#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],c[n+1],d[m+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[m+1]={};
		int p=1;
		for(int j=i;j<=n;j++){
			c[p++]=a[j];
			if(b[a[j]]==0||b[a[j]]>p) b[a[j]]=p;
			else p=b[a[j]];
		}
		for(int j=1;j<p;j++){
			d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
} 
