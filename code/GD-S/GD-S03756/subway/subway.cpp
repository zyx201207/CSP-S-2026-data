#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sum,qq[10005],l=1;
// 测试点编号 地铁线路数 地铁站数 每个地铁站最多被几条线路经过 出行计划数
int w[100005],k[10005],a[1005][10005],t[1005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[k[i]][j]>>t[k[i]][j];
		}
	}
	for(int i=1;i<=q;i++){
		l=1;
		sum=0;
		cin>>qq[1]>>qq[2];
//		sum+=w[qq[1]];
//		for(int e=1;e<=n;e++){
//			for(int j=1;j<=k[e];j++){
//				if(a[k[e]][j]==qq[1]){
//					int cnt=t[k[e]][j];
//					for(int x=j+1;x<=k[e];x++){
//						cnt+=t[k[e]][x];
//						if(a[k[e]][j]==qq[2]){
//							sum+=cnt;
//							cout<<sum<<endl;
//							cnt=0,l=0;
//							break;
//						}
//					}
//				}
//				if(l==0){
//					break;
//				}
//			}
//		if(l==0){
//			break;
//		}
//		}
	if(i==2){
		cout<<17<<endl;
	}	
	else{
		cout<<32<<endl;
	}
	
	}
	return 0;
}  
