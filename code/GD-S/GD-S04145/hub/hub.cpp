//start 17:22:20
//这期神了（题目没看懂） 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int u[n+1],v[n+1];
		for(int i(0);i<n;i++){
			cin>>u[i]>>v[i];
		}//Tree已经忘记了 
	}
	cout<<"RP?";//就这样吧(RP++) 
	return 0;
} 
//17:26:03 版本
//T1 样例数据1&2ok，3不知道为什么答案->4000,4也炸了                                                 MAX可能有5pt 
//T2 目前耗时最久的一题，暴力好像写出来了，目前小数据全部ok（大数据全部TLE与MLE）                   MAX可能有24pt
//T3 目前样例一ok，but其他样例除了2是WA之外都是TLE                                                  MAX可能有4pt 
//T4 写完了数据输入 （本. 题. 包. 含. 多. 组. 测. 试. 数. 据. ）（直接输出骗分是不可能了）          MAX可能有(RP++)pt 
/*应该有30~40+pt吧*/ 
//Process exited after 0.00472 seconds with return value 3221225725 <=应该是爆空间了吧 

//18:09:15留言  
/*
  寄希望于T2了，准备退役 
*/ 
