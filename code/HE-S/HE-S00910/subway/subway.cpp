#include<bits/stdc++.h>
using namespace std;
int k;
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,sum=0,num=0;// c,n,m,d,q，分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	cin>>c>>n>>m>>d>>q;
	long long a[10005];
	for(long long q=1;q<=m;q++){
		cin>>a[q];//每个地铁站的地铁口走到站厅需要的时间
		for(long long i=1;i<=n;i++){
			cin>>k;
			for(long long t=1;t<=2*k;t++){
				long long j,u;
				cin>>a[j]>>a[u];
				for(long long r=1;r<=q;r++){
					cin>>x>>y;
				}
				for(long long i=1;i<=n;i++){
					sum=a[q];	
					if(a[i]==y && a[m]<=d){
						sum+=a[t]+a[q]+a[u];
						
					}
					if(a[j]==x && a[m]<=d){
						num+=a[t]+a[q]+a[u];
						
					}
				}
			}
			
		}
	}
	
	
	
	cout<<sum/2<<" "<<num;
}
