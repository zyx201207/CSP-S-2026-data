#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],mx=-1;
int chk(int q){
	int cnt=1,p=m;
	for(int i=q;i<n&&p>0;i++){
		int tt=a[i+1]-a[i];
		if(tt*i<=p){
			p-=tt*i;
			cnt++;
		}
		else break;
	}
	return cnt;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int tp=a[2]-a[1];
	bool qp=1;
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=tp)qp=0;
	}
	if(qp==1){
		int cnt=1;
		for(int i=1;i<=n;i++){
			m-=abs(tp)*i;
			if(m>=0)cnt++;
			else break;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		mx=max(chk(i),mx);
	}
	cout<<mx+1;
	return 0;
}
/*能量水晶（crystal）
【题目描述】
小R有n颗能量水晶，其中第i(1≤i≤n)颗的能量值为整数ai。小R想用其中若干颗
能量水晶合成一颗大水晶，用于合成的水晶必须具有相同的能量值。小R 希望参与
合成的水晶尽可能多。他可以进行至多m次操作。每次操作可以任选一颗水晶，将
其能量值增加1；同一颗水晶可以被重复选择。你需要帮助小R求出，进行至多m次
操作后，他最多能用多少颗能量水晶合成一颗大水晶。
【输入格式】
从文件crystal.in 中读入数据。
输入的第一行包含一个正整数n 和一个非负整数m，分别表示能量水晶的数量和
最多可以进行的操作次数。
输入的第二行包含n 个整数a1, a2, . . . , an，依次表示每颗能量水晶的能量值。
【输出格式】
输出到文件crystal.out 中。
输出一行一个正整数，表示进行至多m 次操作后，小R 最多能用多少颗能量水晶
合成一颗大水晶。
【样例1 输入】
1 5 5
2 1 2 4 8 9
【样例1 输出】
1 3
【样例1 解释】
小R 有5 颗能量水晶，能量值分别为1, 2, 4, 8, 9。他可以对能量值为1 和2 的水晶
分别操作3 次和2 次，使原来能量值为1, 2, 4 的三颗水晶的能量值都变成4，共进行5
次操作。因此小R 可以用3 颗能量水晶合成一颗大水晶。
【样例2 输入】
1 5 8
2 -3 -1 2 2 7
【样例2 输出】
1 4
*/
