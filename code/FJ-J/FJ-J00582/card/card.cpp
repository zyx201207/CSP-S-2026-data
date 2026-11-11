#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005],d[500005];
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--){
		if(d[a[i]])c[i]=d[a[i]];
		else c[i]=i+1,b[i]=1;
		d[a[i]]=i;
	}for(int i=1;i<=n;i++)d[i]=1;
	for(int i=1;i<=n;i++)d[c[i]]+=d[i];
	memset(c,0,sizeof c);
	for(int i=1;i<=n;i++)if(b[i])c[a[i]]+=d[i];
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
}
