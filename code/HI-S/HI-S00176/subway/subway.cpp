#include<bits/stdc++.h>
using namespace std;
long long c,d,q,m,n,w[60000],k[60000],a[600][10000],x,y,t[600][10000],b[60000];
int fff(long long r,long long l){
    for(int i=1;i<=n;i++){
    	int o=0,g=0;
    	for(int j=1;j<=k[i];j++){
    	    if(a[i][j]==r){o++; g=g+t[i][j];}
    	    if(a[i][j]==l){o++; g=g+t[i][j];}
		}
		if(o==2) return g;
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]>=2&&i!=r&&i!=l){
			return fff(r,i)+fff(i,l);
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	for(int j=1;j<=k[i];j++)
    	{
    		cin>>a[i][j]>>t[i][j];
    		b[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		int h=w[x]+w[y];
		h=h+fff(x,y);
		cout<<h<<" ";
	}
	return 0;
}
