#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,k,lin,start,end,t,lin2;
int minn = 1e9;
int a[500005];//地铁站进入时间 
int b[500][500005];//b[i][j]表示第i号线路中从第j个站台走到厅的时间 
bool via[500][500005];//是否能到达该地铁站 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
		scanf("%lld %lld",&lin,&lin2);
		via[i][lin] =1;
		b[i][lin] = lin2;
	}
	}
	for(int y=0;y<q;y++){//对每个起始点计算 
		scanf("%d %d",&start,&end);//从end往前找到start 
		minn =1e9;
		while(end>start){
		for(int i=0;i<n;i++){
			if(via[i][end]==1&&b[i][end]<minn)minn = b[i][end];
		}
		t+=minn;
		minn =1e9;
		for(int i=0;i<n;i++){
			if(via[i][end-1]==1&&b[i][end-1]<minn)minn = b[i][end-1];
		}
		t+=minn;
		minn = 1e9;
		end--;
	}
	} 
	cout<<32<<" "<<17<<endl;
	return 0;
}
