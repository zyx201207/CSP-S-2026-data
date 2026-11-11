#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int kk,x,y;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>kk>>k[i];
	for(int i=1;i<=q;i++)
		cin>>x>>y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
