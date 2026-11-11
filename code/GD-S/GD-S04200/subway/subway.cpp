#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//n线,m站,d站最多线,q计划
int k_ti[600]={};//口-厅 
int x_z[600][600]={};//[1][2]第1条经过的第2站 
int ti_ta[600][600]={};//厅(站)-台 (线)
int bi[600][600]={};
bool xb[600]={};
int mbin(int top,int end){//路线 
	if(top==end)return 0;
	int time=100000;
	for(int i=1;i<=n;i++){
		if(bi[top][i]!=0&&xb[i]==0){
			xb[i]=1;
			time=min(time,mbin(i,end)+bi[top][i]);
			xb[i]=0;
		}
	}
	return time;
}
int mcin(int top,int end){//路线 
	if(top==end)return 0;
	int time=100000;
	for(int i=1;i<=n;i++){
		if(bi[top][i]!=0&&xb[i]==0){
			xb[i]=1;
			time=min(time,mbin(i,end)+bi[top][i]);
			xb[i]=0;
		}
	}
	return time;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>k_ti[i];
	for(int i=1;i<=n;i++){//路线 
		cin>>x_z[i][0];//经过的地铁站数
		for(int j=1;j<=x_z[i][0];j++){
			cin>>x_z[i][j];
			cin>>ti_ta[x_z[i][j]][i];
		}
		sort(x_z[i]+1,x_z[i]+x_z[i][0]+1);
	}
	for(int i=1;i<=m;i++){//建边 
		for(int j=1;j<=m;j++){
			int a=1,b=1;
			while(1){
				if(a>x_z[i][0]||b>x_z[j][0])break;
				if(x_z[i][a]==x_z[j][b]){//x_z[i][a]共同站 
					if(bi[i][j]==0)bi[i][j]=ti_ta[x_z[j][b]][i]+ti_ta[x_z[j][b]][j];
					else bi[i][j]=min(bi[i][j],ti_ta[x_z[j][b]][i]+ti_ta[x_z[j][b]][j]);
					bi[j][i]=bi[i][j]; 
					a++;
					b++;
				}else if(x_z[i][a]>x_z[j][b]){
					b++;
				}else if(x_z[i][a]<x_z[j][b]){
					a++;
				}
			}
		}
	}
	for(int po=1;po<=q;po++){
		int top,end;
		cin>>top>>end;
		int ans=1000000;
		for(int i=1;i<=n;i++){
			if(ti_ta[top][i]!=0){
				for(int j=1;j<=n;j++){
					if(ti_ta[end][j]!=0){
						xb[i]=1;
						ans=min(mbin(i,j)+k_ti[top]+k_ti[end]+ti_ta[top][i]+ti_ta[end][j],ans);
						xb[i]=0;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
