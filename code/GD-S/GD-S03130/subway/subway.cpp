#include<bits/stdc++.h>
using namespace std;
//    地铁线路数  地铁站数  每个地铁站最多被几条线路经过  出行计划数
int c,n,          m,        d,                            q; 
long long sumt=0;
int num[505],a[505][200000],x[100005],y[100005];
long long w[500005],t[505][200000];
/*
2线路 5站数 20 2计划数
4 1 9 2 5地铁口到站厅时间w
3线路经过站数 1 5  2 7  4 6线路经过j地铁站 站厅走到站台t
3             2 3  3 4  5 7
*/
//bool f[505];
bool fw[505];
long long mint=1e9;
void find(int st,int en,long long tim,int way,int station){
	if(st==en){
		tim+=t[way][station]+w[en];
		mint=min(mint,tim);
		return ;
	}
	for(int i=1;i<=n;i++){//地铁线路数
		if(fw[i]!=0)
			continue;
		for(int j=1;j<=num[i];j++){//地铁站数
			if(a[i][j]==st){
				fw[i]=1;
				//f[j]=1;
				for(int z=1;z<=num[i];z++){//地铁站数
					//if(z!=j){
					//if(f[z]==0){
						//f[z]=1;
						find(a[i][z],en,tim+t[way][station]+t[i][j],i,z);
						//cout<<z<<endl;
						//f[z]=0;
					//}
					//}
				}
				//f[j]=0;
				fw[i]=0;
			}
		}
	}
	return ;
}
void hs(int st,int en){
	memset(fw,0,sizeof(fw)); 
	//memset(f,0,sizeof(f)); 
	mint=1e9+10;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i];j++){
			if(a[i][j]==st){
				fw[i]=1;
				//f[j]=1;
				for(int z=1;z<=num[i];z++){//地铁站数
					//if(z!=j){
					//if(f[z]==0){
						//f[z]=1;
						find(a[i][z],en,w[st]+t[i][j],i,z);
						//find(a[i][z],en,tim+t[way][j],i);
						//f[z]=0;
						//cout<<z<<endl;
					//}
					//}
				}
				fw[i]=0;
				//f[j]=0;
			}
		}
	}
	cout<<mint<<endl;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		hs(x[i],y[i]);
	}
	return 0;
} 
