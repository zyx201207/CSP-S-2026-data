#include<bits/stdc++.h>
using namespace std;
int a[50005];
int c,n,m,d,q;
int x[500005],y[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int mp[1005][1005];
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[j];
		}
		for(int j=1;j<=k;j++){
			for(int s=j+1;s<=k;s++){
				mp[x[j]][x[s]]=mp[x[s]][x[j]]=y[s]+y[j];
			}
		}
	}
	while(q--){
		bool b[1005];
		memset(b,0,sizeof(b));
		int st,ed;
		cin>>st>>ed;
		int c[1005];
		memset(c,0x3f,sizeof(c));
		c[st]=0;
		for(int i=1;i<=m;i++){
			int mn=1e9;
			int k;
			for(int j=1;j<=m;j++){
				if(!b[j]&&mn>c[j]){
					mn=c[j];
					k=j;
				}
			}
			b[k]=1;
			for(int j=1;j<=m;j++){
				c[j]=min(c[j],c[k]+mp[k][j]);
//				cout<<c[j]<<" ";
			}
		}
		cout<<c[ed]+a[st]+a[ed]<<endl;
	}
	return 0;
}/*
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

