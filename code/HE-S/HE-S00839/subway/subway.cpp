#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c, n, m, d, q,w[510],k,a[510][50100],t[510][50100],xb[500100],bj[50100][501],qi,zo;

//c:测试点编号、n:地铁线路数、m:地铁站数、d:每个地铁站最多被几条线路经过，q:以及出行计划数
//Oct31==Dec25?

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			bj[j][++xb[j]]=i;
		}
	}
	ll jsl=0;
	for(int i=1;i<=q;i++){
		cin>>qi>>zo;
		for(int j=1;j<=xb[qi];j++){
			for(int s=1;s<=xb[zo];s++){
				if(bj[qi][j]==bj[zo][s]){
					cout<<t[bj[qi][j]][qi]+t[bj[zo][s]][zo]+w[qi]+w[zo]<<endl;
//					cout<<bj[qi][j]<<" "<<bj[zo][s]<<endl;
					jsl=1;
					break;
				}
			}
			if(jsl==1){
				break;
			}
		}
	}
	return 0;
} 


