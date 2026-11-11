#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,d,q;
int w[N],a[N][N];
int e,f,o,p,s,t,u,v;
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	int ans=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<2*k;j++){
			cin>>a[i][j];
		}
	}
	int x,c;
	for(int i=0;i<q;i++){
		cin>>x>>c;
		for(int i=0;i<n;i++){
			for(int j=0;j<2*k;j++){
				if(x==a[i][j]&&j%2==1){
					e=i,f=j;
				}
				if(c==a[i][j]&&j%2==1){
					o=i,p=j;
				}
				for(int b=0;b<k;b++){
					for(int c=i+1;c<n;c++){
						if(a[i][j]==a[b][c]){
							s=i,t=j,u=b,v=c;
						}
					}
				}
				if(e==o){
					ans=w[f]+a[e][f+1]+a[o][p+1]+w[p];
				}else{
					ans=w[f]+a[e][f+1]+w[p]+a[o][p+1]+a[s][t+1]+a[u][v+1];
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
