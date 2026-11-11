#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[101],k[101],b[1001][10001],b2[1001][10001],su,t,v1,v2,v[101],vh[101],num[10001],v3,v4;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[m];
	for(int f=1;f<=q;f++){
		int x,y,bex[101],bed[101],enx[101],end[101];
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(b[i][j]==x){
					v1++;
					bex[v1]=i,bed[v1]=j;
				}
				if(b[i][j]==y){
					v2++;
					enx[v2]=i,end[v2]=j;
				}
			}
		}
		for(int i=1;i<=v1;i++){
			for(int j=1;j<=v2;j++){
				v4++;
				num[v4]+=b[bex[i]][bed[j]];
				num[v4]+=a[v[1]];
				num[v4]+=vh[1];
				num[v4]+=a[b[enx[i]][end[j]]];
				num[v4]+=b2[enx[i]][end[j]];
			}
		}
		long long minn=-1e9;
		for(int i=1;i<=n;i++){
			if(num[i]>minn)minn=num[i];
		}
		cout<<minn<<endl;
	}
		
		
	
	return 0; 
} 

