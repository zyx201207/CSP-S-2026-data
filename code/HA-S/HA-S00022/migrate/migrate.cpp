#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define int long long
//const int mod=998244353;
//const int mod=1e9+7;
const int N=2e6+5;
using namespace std;
int read(){
	int x=0;
	short f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*((1<<1)+(1<<3))+c-'0';
		c=getchar();
	}
	return ((f)?(-x):(x));
}
int c,t;
//首先考虑特殊性质A
//x为等差数列 => 每两个相邻岛屿之间的距离是相等的
int n,d,x[N];
//为什么我的电脑中下部有一条横着的黑线？
int maxn(int x,int y){
	return ((x>y)?(x):(y));
}
//手打max函数是好文明
int reach(int l,int r){
	int mid=l,step=1,last=l;
	while(mid<r){
		++mid;
		if(x[mid]-x[mid-1]>d) return -1;
		if(x[mid]-x[last]>d) last=mid-1,++step;
	}
	return step;
}
void solveA(){
	n=read(),d=read();
	for(int i=1;i<=n;++i) x[i]=read();
	int dis=x[2]-x[1];
	int q=d/dis;
	if(d<dis*2){
		//如果飞行的时候中间不能跨岛，那么显然不存在
		cout<<"0\n";
		return;
	}
	//接下来我们考虑
	//如果中间只能跨一座岛
//	if(dis*2<=d&&d<dis*3){
//		cout<<n-3<<'\n';
//		return;
//	}
	//如果中间可以跨两座以及上的岛屿的话
	//那么也是不存在的
	//骐骥一跃飞走了
//	if(d>=dis*3){
//		cout<<"0\n";
//		return;
//	}
	//测了大样例
	//有些不该是0的给判成0了
	//抓了一个
	//n=10,d/dis=10,输出5
	//为什么？
	//10个点，怎么飞都能一次飞过去啊
	//甚至不是long long的锅
	//what can I say
	//草
	//看错样例了
	//实际出锅的是d=21,dis=7这一组
	//n=10,应输出5
	//合着我删掉的思路是对的?
	int len=q*2-1;
	if(len<0){
		cout<<0<<'\n';
		return;
	}
	cout<<maxn(n-len,0)<<'\n';
	return;
	//布什戈门
	//我瞎改一通
	//然后你跟我说对了?
	//现在108pts到手，如果不挂分的话
	//接下来是暴力
}
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;++i) x[i]=read();
	if(n<=3){
		cout<<"0\n";
		return;
	}
	int ans=0;
	//如果从A到B需要1步，从B到C需要1步，从A到C需要两步
	//那么B就是一个中转站
	//如果这样的B恰好有两个，那么(A,C)就是一个合法的答案
	//这是合法答案的充分条件
	//那么必要条件呢?
	//这个是必要的吗?
	//直觉说是的
	for(int i=1;i<=n;++i){
		for(int j=i+3;j<=n;++j){
			int cnt=0;
			for(int k=i+1;k<=j-1;++k){
				if(cnt>2) break;
				if(reach(i,k)==1&&reach(k,j)==1&&reach(i,j)==2) ++cnt;
			}
			if(cnt==2) ++ans;
		}
	}
	cout<<ans<<'\n';
	return;
}
//小样例全部通过
//时间复杂度目测n^4
//管他有没有分呢
//写了再说
signed main(){
	fre("migrate")
	c=read(),t=read();
	if(c==11||c==12){
		while(t--) solveA();
		return 0;
	}
	while(t--) solve();
	return 0;
}
