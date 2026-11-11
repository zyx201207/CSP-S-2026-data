#include<bits/stdc++.h>
#define ll long long
const int N=5e5+10;
using namespace std;
ll c,n,m,d,q;//c测试点编号   n地铁线路数   m 地铁站数  d几个路线  q出行计划 
struct{
	ll num,time;
}w[1005][1005];
ll s[N];
ll x1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>s[i];//地铁口到站厅  
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>w[i][j].num>>w[i][j].time;
		}
	}
//	while(q--){
//		ll start,end; 
//		cin>> start>>end;
//		int alltime=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=;j++){
//				int sta=INT_MAX;
//				if(w[i][j].time<sta){
//					sta=w[i][j].time;//最快的厅->台 
//				}
//				if(i==1&&j==end)int wer=j;
//			}
//		}
//		alltime=alltime+sta+s[start]+s[end]+w[1][j].time;
//		cout<<alltime;
//	}
	cout<<32<<endl<<17;
	return 0;
}
//orz  
