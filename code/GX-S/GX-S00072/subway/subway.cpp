#include<bits/stdc++.h>
using namespace std;
map <  int, map<int,int> > t;
int w[500005];
int x[100005];
int y[100005];
int dp[500005];
int main(){
//  贪心  第i个站台的最优应是前一位加上这一位的最小数值，可是上一位最优的路线不一定与这   
//	一位的最小值在同一条轨道上，需要把两条路线的差补上而且可能上一条最有的路线与目前最小    
//  值位置连接不起来      （终于找到切换输入法了！！！）
//-----------------硬模屎山代码---------------
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int zt,tm;
			cin>>zt>>tm;
			t[i][zt]=tm;
		}
	}
	int maxy=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		maxy=max(maxy,y[i]);
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		ans+=w[x[i]];
		if(x[i]+1==y[i]){
			int minn=1e9;
			int mj;
			for(int j=1;j<=n;j++){
				if(t[j][x[i]]!=0){
					minn=min(minn,t[j][x[i]]);
				}
			}
			for(int j=1;j<=n;j++){
				if(minn==t[j][x[i]]){
					mj=j;
					break;
				}
			}
			ans+=minn;
			ans+=t[mj][y[i]];
		}else{
			int lj=0;
			for(int j=x[i];j<=y[i];j++){
				int mj=0;
				int minn=1e9;
				for(int k=1;k<=n;k++){
					if(t[k][j]!=0){
						minn=min(minn,t[k][j]);
					}
				}
//				cout<<"min="<<minn<<" ";
				for(int l=1;l<=n;l++){
					if(t[l][j]==minn){
						mj=l;
						break;
					}
				}
//				cout<<"选了第"<<mj<<"条路线"<<" ";
				ans+=minn;
				if(j!=x[i]){
					if(lj!=mj){
						int maxn=max(lj,mj);
						int minn=min(lj,mj);
						for(int o=minn;o<maxn;o++){
							ans+=t[o][j];
//							cout<<"    ans++="<<ans<<" o="<<o<<" ";
						}
						lj=mj;
					}
				}else{
					lj=mj;
				}
//			cout<<"J="<<j<<"时，ans="<<ans<<endl;
			}
		}
		ans+=w[y[i]];
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
