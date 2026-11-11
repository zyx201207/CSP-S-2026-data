#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
long long w[500005],k[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++){
		cin>>k[i][1];
		for(long long j=1;j<=k[i][1];j++){
			cin>>k[i][j+1];
		}
	} 
	int both[500005][2];
		long long z=1;
		for(long long i=2;i<=n;i+=2){
			for(long long j=2;j<=n;j+=2){
				if(k[1][i]==k[2][j]){
					both[z][1]=k[1][i];
					both[z][2]=i;
					break;
				}
			} 
		}
		z-=1;
	for(long long qu=1;qu<=q;qu++){
		long long x,y;
		cin>>x>>y;
		for(int i=1;i<=z;i++){
			if(x==both[i][1]){
				for(long long l=2;l<=n;l+=2){
					if(k[1][l]==y){
						cout<<k[1][l+1]+k[1][both[z][2]];
						break;
					}
					if(k[2][l]==y){
						cout<<k[2][l+1]+k[2][both[z][2]];
						break;
					}
				}
			}
			if(y==both[i][1]){
				for(long long l=2;l<=n;l+=2){
					if(k[1][l]==x){
						cout<<k[1][l+1]+k[1][both[z][2]];
						break;
					}
					if(k[2][l]==x){
						cout<<k[2][l+1]+k[2][both[z][2]];
						break;
					}
				}
			}
		}
	}
	return 0;
}
