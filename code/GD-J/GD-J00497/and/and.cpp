#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int,int>;
const int N=2e5+9,M=4e5+9,inf=1e9+9;
const int mode=998244533;

int a[N];
bool vis[N];//当为true就跳过，已经不用管了 
bool ans[33];

void solved(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int k=30;k>=0;k--){//好像小于30位，不过无所谓了 
	
		queue<int> qu;int cnt=0;
		
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
//			cout<<"test "<<k<<' '<<a[i]<<endl; 
			if((a[i]>>k)&1)cnt++;
			else qu.push(i);
		}
		if(cnt<m)continue;
		while(!qu.empty())vis[qu.front()]=true,qu.pop();
		ans[k]=true;
	}
	int now=1 , sum=0;
	for(int i=0;i<=30;i++){
		if(ans[i])sum+=now;//类似于quick power的累计贡献 
		now*=2;
	}
	cout<<sum;
}
/*
4 2
3 15 12 12

*/
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solved(); 
	return 0;
}
/*
思路：按位与
原来是按位与我还以为按位或
那么按位与就好玩了，我们还是拆位
还是从大到小考虑，可以证明，当某个二进制位的数字大于等于m时，它就合法
而我们需要的是最大，所以我们会优先选择最大的合法二进制位
然后对于这个最大的二进制合法位的所有数字
我们再继续向下判断每个数位是否大于等于m
不过这样显然可能会导致超时，即最后每个数都最大且相同
此时我们就可能连续压入31次n个数字
不过看上去还好
我觉得是这样的，每次筛掉一些元素，当一个二进制位合法时，剩下的
还在这个合法集内的二进制位不合法数字就可以去掉，然后我们考虑下一个

总体流程：
我们初始认为每个数字都合法，然后扫一遍，存储每个数字的31位
都是否合法，然后再扫31遍,每一次大体如下
若这个数字被淘汰掉
我们就不统计它当前二进制位的贡献
若这个数字没被淘汰掉，那我们就统计它的贡献
若没贡献，就压入栈 
然后若没被淘汰掉的合法数字的二进制位大于等于m 
我们就把栈里的都标记为淘汰 
总时间 O(31*n = 6e6) 可以通过
总空间 2n  内部栈可能有点大，不会爆吧，递归栈空间才会不用担心 
数组2e5+9 没问题开对了， ans 也大不用担心re 
*/





