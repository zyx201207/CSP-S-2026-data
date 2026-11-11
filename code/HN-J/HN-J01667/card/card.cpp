#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N],nxt[N],ans[N];
struct node{
	int x,id;
}bb[N];
bool cmp(node x,node y){
	return x.x<y.x;
}
int to[N],rd[N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)ans[a[i]]++;
	for(int i=n;i>=1;i--){
		if(!nxt[a[i]])nxt[a[i]]=i;
	}
	for(int i=1;i<=m;i++)bb[i]={nxt[i],i};
	sort(bb+1,bb+1+m,cmp);
	for(int i=1;i<m;i++){
		to[bb[i].id]=a[bb[i].x+1];
		rd[a[bb[i].x+1]]++;
	}
	for(int i=1;i<=m;i++){
		if(!rd[i])q.push(i);
	}
	while(q.size()){
		int d=q.front();q.pop();
		int v=to[d];
		ans[v]+=ans[d];
		rd[v]--;
		if(!rd[v])q.push(v);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
/*
怎么50min就把前三题写了？？

首先不那么容易发现，当某个回合某个数他前面的数在后面都不会出现时

也只有这种情况他能在最后留下

接着一个比较容易发现的，第一个数到第一个数最后出现位置的数都是无用的

诶，然后我们发现这第一个数最后一个出现的位置后的一个数亦然，

且他是一定会在最后留下的 

到这里我们已经得到了一个O(nm) 的算法，可以通过前20个测试点！！ 

不对啊，又搓了一组数据后，发现只要值相同，那么最终对答案的贡献也相同，那我不AK了吗？！ 

不不不，还有一点细节，如何加权呢？ 

再看手搓的数据容易发现，到最后一个位置后的下一个是可以直接将他的权值序列加在我后面的

那就简单了 

我 1h10min AK 了？？ 

不得不说 T4 真是好题

J 组真的好简单，今天上午状态都不怎么样 
*/
