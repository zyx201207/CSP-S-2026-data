#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int,int>;
const int N=5e5+9,M=3e5+9,inf=1e9+9;
const int mode=998244533;
int fir[N];//第一次出现的次数 
bool vis[N];//当前下标元素之前有没有出现过相同元素 
int wl[N],wr[N];//每个下标的专属区间
int cnt[N];//每个下标的区间的贡献次数
int cf[N];//差分标记实现位置 
int nex[N];//下一个跳跃的位置 
int ans[M];//最终询问的每个点数出现次数 
int a[N];///每个下标的对应点数 
void solved(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=n;i>=1;i--){
		int w=a[i];
		
//		cout<<"game "<<i<<" color "<<w<<endl;
		
		if(fir[w]==0)fir[w]=i;//前面没出现过 
		else vis[i]=true;//前面出现过
		
//		cout<<"first time "<<fir[w]<<endl;
		
		if(fir[w]==n)wl[i]=n,wr[i]=n;//此时不可能出现下一个跳跃
		else {
			int pos=fir[w];
			if(vis[pos+1])wl[i]=wr[i]=pos,nex[i]=pos+1;//此时连跳 
			else{//对于nex=0的，我们管都不需要管 
				int ed=nex[pos+1];
				nex[i]=ed;
				wl[i]=pos,wr[i]=ed-1;//实际贡献 
			}
//			cout<<"nex jump "<<nex[i]<<endl;
		} 
	}//在上面，我们不断的增加新元素,从后往前知道每个下标的专属区间和下一个跳的起始点 
	
	for(int i=1;i<=n;i++){
		cnt[i]++;//处理差分，每个位置都至少有一次区间
		cf[wl[i]]+=cnt[i],cf[wr[i]+1]-=cnt[i];
		cnt[nex[i]]+=cnt[i];
	}
	int now=0;
	for(int i=1;i<=n;i++){
		int w=a[i];
		now+=cf[i];
		ans[w]+=now;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
}
/*
4 3
1 2 1 3

3 1 4
*/
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);//最后进行一遍验算 
	solved(); 
	return 0;
}
/*
大体体实现
从后往前扫描添加 
我们要维护几个东西
每个元素第一次出现位置
当前下标局数的贡献
细化地，这个贡献是由两个部分组成的
下一个跳的位置
它的最远元素下标到下一个跳之前一个下标所构成的区间

还可能记载的，就是当前下标之前，有没有出现过相同点数

然后我们，对于每个下标，给它的区间打上价值，再增加它前一个跳的次数
这一部是从前往后扫的
前一个跳的次数，大概就是一个给前一个跳 打一个乘法标记
总空间 4 * 5e5 * 8 + 5e5 = 1.6e7 不会超过 1024 mb=1e9b
总时间 O(3*n+m) 反向一遍正向二遍 输出m一遍 
数组也开对了 ok! 
*/

