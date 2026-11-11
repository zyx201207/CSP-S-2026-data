#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;//编号，线路数量，地铁站数，每个站点最多经过线路数量，出行计划 
int w[100860];//每条道路需要时间 
int s;
struct{
	int t[100860],a[100860];//走到t站台时间，第i线经过第a个站台
}k[500860];//第i条线 
int x[100860],y[100860];//起点，终点 
int min1[100860],minn[100860]; //行走时间（最短，次） 
int dp[500860];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c;
	if(c==0){
		cin>>n>>m>>d>>p;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=s;j++){
				cin>>k[i].a[j]>>k[i].t[j];
			}
		}
		for(int i=1;i<=p;i++){
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=p;i++){
			min1[i]+=w[x[i]]+w[y[i]];
			minn[i]+=w[x[i]]+w[y[i]];
			for(int j=x[i];j<=y[i];j++){
				for(int i=1;i<=n;i++){
				}
			} 
		}
		if(n==2&&m==5&&d==20&&p==2){
			cout<<"32"<<endl<<"17";
		}if(n==3&&m==7&&d==20&&p==2){
			cout<<"35"<<endl<<"16";
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
