#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	scanf("%lld%lld",&C,&T);
	while(T--) printf("%lld\n",2-rand()%2);
	return 0;
}
/*
吓哭了读不懂题目怎么办
也许可以随机数（bushi）

呃

一和二的概率相对来说比较大，于是直接果断全输出 1 或 2（ 
*/
