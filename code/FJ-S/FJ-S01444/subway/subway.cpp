#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll B=1e12;
const ll N=505;
ll ccccc,n,m,ddddd,q,ans[N];
ll w[N],kk[N],dd[N],kdx;
ll map[N][N];
int main(){
	memset(map,0x3f,sizeof(map));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccccc>>m>>n>>ddddd>>q;
	for(ll i=1;i<=n;i++){cin>>w[i];}
	for(ll i=0;i<m;i++){
		ll k,lastp,lastc;
		cin>>k;if(k==0)continue;
		for(ll j=1;j<=k;j++){
			cin>>kk[j]>>dd[j];
			for(ll l=1;l<=j;l++){
				map[kk[l]][kk[j]]=min(map[kk[l]][kk[j]],dd[l]+dd[j]);
				
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			map[i][j]=min(map[j][i],map[i][j]);
		}
	}
	ll popo=0,yuyu=1;
	for(;yuyu<n;){
		popo+=1;
		yuyu=yuyu<<1;
	}
	for(ll i=1;i<=popo;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				if(k==j)continue;
				if(map[j][k]<B){
					for(ll l=1;l<=n;l++){
						if((l==k)||(l==j))continue;
						if(map[k][l]<B){
							map[j][l]=min(map[j][l],map[j][k]+map[k][l]);
							map[l][j]=map[j][l];
						}
					}
				}
			}
		}
	}
	for(ll i=0;i<q;i++){
		cin>>ccccc>>ddddd;
		ans[i]=map[ccccc][ddddd]+w[ccccc]+w[ddddd];
	}
	for(ll i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
}
