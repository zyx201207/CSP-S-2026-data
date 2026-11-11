#include<bits/stdc++.h>
using namespace std;
int rd(){
	int x=0;
	int f=1;
	char c=getchar();
	if(c=='-') f=-1;
	else x=(c^48);
	while(1){
		char c=getchar();
		if(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48);
		else break;
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	return 0;
}
/*
二分，以1为根

每次有一个x表示当前的答案

记fi表示以i为根的子树需要使得答案为x的最小数量
转移是简单的，O(n)

然后O(n)预处理出fi，考虑看是否可以选择两个点，使得

fi+fj<=k

先枚举一个子树，设枚举到i子树 

那此时不在i的子树的叶子就会与i很远

那么此时就要把叶子很深的用第二个树

那么就要把叶子合并了

贪心的，可能先合并最深的更优 

f k c c f
*/

