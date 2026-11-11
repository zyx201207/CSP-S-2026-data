#include <bits/stdc++.h>
using namespace std;
namespace contest{
	int n;
	long long m;
	long long a[500005];
	long long sum[500005];
	int main(){
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		for (int i=1;i<=n;i++){
			if (a[i]*(i-1)*1LL-sum[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}	
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	contest::main();
	return 0;
}
/*
这 T1 做法好像假了啊，不管了没时间了 
J组总结：
T1 水
T2 调了1.5h 0pts->0pts，最后还是打暴力 0pts->68pts
T3 暴力+特判
T4 暴力失败
难度预估：入门 普及 普及 普及+/提高- 
估分 100+68+(50+?)+?=2xx pts
估计 2=（去年 CQ 1= 295）
至少比上次好（2024年J组100pts 3=）
*/
