#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	
	
	return 0;
}
/*
都到这里了，我想上迷惑行为大赏可以吗/kel 
使最小值的最大值最小，二分没跑
像树形DP状物，但是数据给到1e6
 
*/ 
