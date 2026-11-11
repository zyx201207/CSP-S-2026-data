//版本1 最终版 3：22打完 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){
	ll a=0,f=1;
	char c=getchar();
	while (c<'0' or c>'9'){
		if (c=='-')f=-1;
		c=getchar();
	}while (c>='0' and c<='9'){
		a=a*10+c-48;
		c=getchar();
	}return a*f;
}
ll n,m,a[N],pres[N];
ll ans=0,res=0;
ll t=0;
ll msum(ll l,ll r){//区间[l,r]全部合并的代价 
	return a[r]*(r-l)-(pres[r-1]-pres[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	pres[0]=0;
	n=read();m=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
	//你说你着什么急呢，排完序再前缀啊！！！ 
		pres[i]=pres[i-1]+a[i];
	}
	//思考使用一个指针，表示最远可以合成的距离 
	t=1;//t做指针,重合则代表一个都合成不了 
	for (int i=1;i<=n;i++){
		while (msum(t,i)>m and t<=i)t++;
		ans=max(ans,i-t+1); 
	}
	cout<<ans;
	return 0;
}
/*
先排序，然后从小到大
考虑到只能是能量值+1，所以我们只关注这一项前面的项
然后计算以该水晶为目标大小最多几块
g[i]为前i项合成一块总共的消耗 
消耗值应当为 g[i-1]+prs[1,i-1]这里是差值的前缀和 

我们不难发现一定是往前找的越是考前，消耗越大，所以
我们考虑预处理出每个以i为起点，向左的最大的<m的个数

我们惊奇的发现对于 a[i~j]的全部合并为
长度*末项值-前缀和（不包含末项 
*/
