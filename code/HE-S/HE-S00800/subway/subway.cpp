#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int c,n,m,d,q;//c-->测试点编号 n-->地铁线路数 m-->地铁站数 d-->最多经过路数 q-->出行计划数 
int w[N];
int f[5]={1,2,3,4,5};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//输入 
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];//从地铁口走到站厅的时间 
	}
	int k;
	cin>>k;//地铁站数
	int a[n],t[n];
	for(int i=0;i<2*k;i++){
		cin>>a[i]>>t[i];//经过站数 所需时间 
	}
	int x[n],y[n];
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];//起点和终点的编号
	}
//-------------
	int time=0;
	int i=0;
	while(n=0){
		i++;
		while(a[i]==y[i]){
			if(x[i]==a[i]){
				time+=w[i];
				if(a[i]-a[i-1]){
					time+=t[i];	
					if(a[i]==y[i]){
						time+=w[i];
					}
				}
			} 
			else{
				time+=t[i];
			}
		}
		n--;
		cout<<time<<endl;
	}
		
	return 0;
} 
