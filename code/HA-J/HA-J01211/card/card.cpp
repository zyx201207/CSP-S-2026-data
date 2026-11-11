#include<bits/stdc++.h>
using namespace std;
int n,m,a[500040],b[300024],c[300024],d[300024],e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){e=0;for(int j=1;j<=m;j++)d[j]=0;for(int j=i;j<=n;j++){
	if(d[a[j]]){for(int k=d[a[j]]+1;k<=e;k++)d[c[k]]=0;e=d[a[j]];}else e++,c[e]=a[j],d[a[j]]=e;}
	for(int k=1;k<=e;k++)b[c[k]]++;}
	for(int i=1;i<m;i++)cout<<b[i]<<' ';cout<<b[m];
	return 0;
}
