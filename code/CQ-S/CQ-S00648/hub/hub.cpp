#include<bits/stdc++.h>
#define online
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
int main(){
#ifdef online
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	ll RP=LLONG_MAX;
	cout<<RP;
	
	return 0;
}
/*
怎么又双叒叕是图论...

今天某某某是怎么了。 

这道题看起来很有意思。其实就是要找最优划分，然后让所有城市中，距离选择城市最近的值的最大值最小。

好绕啊...

但是我理解就行。

可以二分吗？

注意到这道题目给3s。

哦！是一棵树！

和LCA有关？ 

求最远点最近。怎么又是2个连通块！ 

我发现一个事情：两个连通块似乎必然经过直径。

我们先思考：如果给你一条直径，你要怎么划分？

如果只有一个点，那么就是直径的中点。 

否则就是左半部分的中点和右半部分的中点。 

好的，现在选择了两个节点了。

我们可以拿到5*3=15分。

算了走了。
---
18:26 240分归来！
没什么了，打点奇奇怪怪的吧。ll RP=LLONG_MAX! 别炸 plz，保住啊！ 


*/
