#include<bits/stdc++.h>
using namespace std;
const int N1=20005,N2=505;
int c,n,m,d,q,ans=0,s,e;
int suba[N2][N1],atw[N2]={0};
int subt[N2][N1];
void edfs(int way,int w){
//	cout<<"way:"<<way<<" e:"<<e<<endl;
	for(int i=w;i<atw[way];i++){//尝试下几站 
		if(suba[way][i]==e){//如果到达目的地 
			ans+=subt[way][i];
			cout<<ans<<endl;
			ans-=subt[way][i];
		}
	}
}
void sdfs(){//坐上地铁 
	for(int i=1;i<n;i++){//找匹配线路 
		for(int j=0;j<atw[i];j++){//查找该线路是否存在上车点 
			if(suba[i][j]==s){//存在 
				ans+=subt[i][j];
//				cout<<"edfs("<<i<<','<<j<<')'<<endl;
				edfs(i,j);//已上车，准备下车 
				ans-=subt[i][j];
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			suba[i][atw[i]]=a;
			subt[i][atw[i]]=t;
			atw[i]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		ans=w[s]+w[e];
		sdfs();//开始乘坐 
		//cout<<ans<<endl<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
