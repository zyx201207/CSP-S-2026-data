#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int z=0,y=0;
int n;
long long tj[N];
char zf[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	z=1,y=n;
long long xg=0;
	for(int i=1;i<=n;i++){
		cin>>tj[i]>>zf[i];
	}
	while(z<y){
		long long dqz=tj[z],dqy=tj[y];
		char nz=zf[z],ny=zf[y];
		if(dqy>=dqz){
			if(ny==nz){
				tj[y]-=dqz;
				tj[z]-=dqz;
			}
			else{
				xg+=dqz;
				tj[y]-=dqz;
				tj[z]-=dqz;
			}
		}
		else{
				if(ny==nz){
				tj[y]-=dqy;
				tj[z]-=dqy;
			}
			else{
				xg+=dqy;
				tj[y]-=dqy;
				tj[z]-=dqy;
			}
		}
		if(tj[z]==0)z++;
		if(tj[y]==0)y--;
	}cout<<xg;
	
}
