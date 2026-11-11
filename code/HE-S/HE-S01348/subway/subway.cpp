#include<bits/stdc++.h>
using namespace std;
const int NT=1006;
const int N=1e5+5;
	long long a[NT][NT];
	long long t[NT][NT];
long long c,n,m,d,q,w[N],k,x[N],y[N],cnt=0,same[N]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int m[N];//存储k为判断线路 
	for(int i=1;i<=n;i++){
		cin>>k;
		m[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int xian_st=0,xian_end=0;//判断是否在同一条地铁线 
	bool flag=false;
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
			for(int j=1;j<=n;j++){
			for(int z=1;z<=m[i];z++){
			if(a[j][z]==x[i]){
				xian_st=j;
				if(xian_end==xian_st){
					flag=true;
					j+=n;
				}
			}
			if(a[j][z]==y[i]){
				xian_end=j;
				if(xian_end==xian_st){
					flag=true;
					j+=n;
				}
			}
		}
		}
		if(flag==true){//在同一条地铁线上 
			cnt+=t[xian_end][y[i]];
			cnt+=t[xian_st][x[i]];
			cnt+=w[y[i]];
			cnt+=w[x[i]];
			cout<<cnt<<endl;
		}
		int no_st=0,no_end=0;
		int changed=INT_MAX;
		if(flag==false){
			for(int j=1;j<=n;j++){
			for(int z=1;z<=m[i];z++){
				if(a[j][z]==x[i]){
					no_st=j;
					j+=n;
				}
				if(a[j][z]==y[i]){
					no_end=j;
					j+=n;
				}
			}
			}
			for(int j=1;j<=m[no_st];j++){
				++same[a[no_st][j]];
			}
			for(int j=1;j<=m[no_end];j++){
				++same[a[no_end][j]];
				if(same[a[no_end][j]]>=1&&t[no_st][j]+t[no_end][j]<=changed){
			  changed=t[no_st][j]+t[no_end][j];
				}
			}
			cnt+=changed;
			cnt+=t[no_st][x[i]];
			cnt+=w[y[i]];	
			cnt+=w[x[i]];
			cnt+=t[no_end][y[i]];
			cout<<cnt<<endl;				
		}
		cnt=0;
		flag=false;
		xian_st=0,xian_end=0;
	}
	return 0;
}
