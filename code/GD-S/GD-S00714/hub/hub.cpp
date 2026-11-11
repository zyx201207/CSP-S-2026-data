#include <bits/stdc++.h>
const int MAX = 5e5 + 5;


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::cin.tie(0) -> sync_with_stdio(0);

	return 0;
}
/*
梁皓然 于2026年10月31日16：55 跳过第三提抵达这里
好了好了，已经两题了，开始打暴力了

坏了坏了，好像是 TopTree ？？？
题意可以转化为，在里面割出一个或者两个子树，子树大小恰好为 k 
然后求里面每个点之间距离的最大值，令这个最大值最小

看看割一个出来怎么做？

*/