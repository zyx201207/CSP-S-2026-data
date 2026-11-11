#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5500,inf=1e17;
int n,d,x[N],to[N][N],ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		cin>>n>>d>>x[1];
		for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) to[i][j]=inf;
		for(int i=2;i<=n;i++) cin>>x[i],x[i]+=(1-x[1]);
		x[1]=1;ans=0;
		for(int i=1;i<=n;i++){
			int lst=i,num=1;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				if(x[j]-x[lst]<=d) to[i][j]=num;
				else lst=j-1,to[i][j]=++num;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int mi=to[i][j],cnt=0;
				if(mi==inf||mi==1) continue;
				for(int k=i+1;k<j;k++) if(to[i][k]+to[k][j]==mi) cnt++;
				if(cnt==mi) ans++;
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
/*
16:27:50 没啥思路了，决定打暴力，感觉性质B好打，但好像没啥思路。为什么只要跟计数和dp容斥沾边我就不会啊！！！ 
16:51:04 打完暴力了，O(n^3)，本来数组大小只有350的，但转念一想，开成5500又不会炸，如果CCF少爷机发力了呢？想多了，1e11可不是开玩笑
16:53:55 尝试优化成O(n^2)，这样就多16分了 
16:55:37 算了，先goto T4
期望得分24 
预估难度：蓝
已检查freopen 
*/
