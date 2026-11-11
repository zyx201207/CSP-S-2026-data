#include <bits/stdc++.h>
#define sbccf 0
using namespace std;
long long a[50005],cf[50005];
long long n,m;
int main(){
	//依旧开题先睡半小时 真舒服
	//才三点 急什么啊我又不会做 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n; i++){
		cin>>a[i];
		cf[i] = a[i] - a[i-1];
	}
	
	//怎么办  感觉只能暴力但不知道怎么写
	//嘎达嘎达
	//我想试试枚举每一种情况，就是加或者不加
	//不行！ 
	//有特殊性质！试试看 
	//差分
	
	sort(cf+1,cf+1+n);//试试把这行注释掉
	//不行，这个必须保留 
	long long cnt = 0,tot = 0,sum = 0;
	for(int i = 1;i <= n;i++){
		if(tot + sum <= m)	cnt++;
		sum += cf[i]*i;
	}//我到底在写什么...... 
	cout<<cnt;
	
	
	return sbccf;
} 
//我该不会......把正解瞪出来了吧？！  
//假的  这怎么可能是正解 
//会不会是longlong的问题？
//ccf我真没时间陪你闹了 
//哎哟我去  3221225477都来了这把彻底没救了 
//估计有25左右吧
//原神uid310217294 官服 欢迎交友
//可能不常在线
//我要AFO了（悲） 
//两个小时了 下一题见 
