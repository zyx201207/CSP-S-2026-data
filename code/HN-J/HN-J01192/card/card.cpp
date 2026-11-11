#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
int a[500005];
int t[500005];//桶
vector<int> g[500005];
int siz[500005];
int ans[500005];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[n-i+1];
	for(int i=1;i<=n;i++)
		if(!t[a[i]])
			t[a[i]]=i;
	for(int i=1, now=0;i<=n;i++){
		if(t[a[i]]==i){
			g[now].push_back(i);
			now=i;
			siz[i]++;
		}
		else{
			siz[t[a[i]]]++;
			now=t[a[i]];
		}
	}
	for(int i=n;i>=1;i--)
		for(auto v:g[i])
			siz[i]+=siz[v];
	int s=0;
	for(int i=1;i<=n;i++)
		if(t[a[i]]==i)
			ans[a[i]]=siz[i];
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
/*
注意到一个小性质：从左往右插入等价于从右往左插入
所以我们可以一个reverse且不影响答案
这样就可以从1到n一次插入
同时可以发现每次还原的结果就是左边离他最近的点
然后可以建处理每个局面的个数
接下来可以建一棵树
其中若u->v则代表v局面时u局面添加一个a_v所形成的
然后树上统计子树和就是这个局面的出现次数
然后在遍历一遍，答案为\sum_{i=1}^n siz_i \times a_i 

今年感觉比去年还水，一个小时就能ak，水成啥了，没点难度
去年的t4是个dp且还是要推一会式子的
今年什么鬼，就是个性质题
感觉顶多算个黄
好无聊 







由前3题注释可知：我一定能上魔怔行为大赏的（确信） 
为了方便作者，我决定告诉你，合并后为jun cat love ya cat （郡猫爱雅猫） 
同时，请不要把我的准考证泄露出去，否则我会被同学大4 
*/
