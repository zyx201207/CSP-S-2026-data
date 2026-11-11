#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e15;
int n,m,c,d,q;
int w[1000086];
int t[1000086];
int a[1000086];
int ed[1005][1005];
int flo[1005][1005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)ed[i][j]=flo[i][j]=MAXN;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		cin>>a[j]>>t[j];
		for(int l=1;l<=k;l++)
		  for(int r=l+1;r<=k;r++){
		  	flo[a[l]][a[r]]=flo[a[r]][a[l]]=ed[a[l]][a[r]]=ed[a[r]][a[l]]=min(ed[a[l]][a[r]],t[l]+t[r]);
		  }
	}
    for(int i=1;i<=m;i++){
    	for(int j=i+1;j<=m;j++){
    		for(int k=i;k<=j;k++)flo[j][i]=flo[i][j]=min(flo[i][k]+flo[k][j],flo[i][j]); 
		}
	}
	while(q--){
		int as,bs;
		cin>>as>>bs;
		cout<<flo[as][bs]+w[as]+w[bs]<<endl;
	}
	return 0;
}
/*

0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2




0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3










*/
