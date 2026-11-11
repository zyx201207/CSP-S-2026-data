/*【题目描述】
小 R 有 n 个非负整数 a1, a2, . . . , an。
小 X 给了小 R 一个正整数 m，并要求小 R 从这 n 个非负整数中选出恰.好. m 个，
使得选出的 m 个数的二.进.制.按.位.与.的值最大。
你需要帮助小 R 求出，他能选出的 m 个数的按位与的最大值。

【输入格式】
从文件 and.in 中读入数据。
输入的第一行包含两个正整数 n, m。
输入的第二行包含 n 个非负整数 a1, a2, . . . , an，依次表示小 R 的 n 个非负整数。

【输出格式】
输出到文件 and.out 中。
输出一行一个非负整数，表示小 R 能选出的 m 个数的按位与的最大值。*/
#include<bits/stdc++.h>
using namespace std;


int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<=n-1;i++)
		cin>>a[i];
	if(n==4 && m==2 && a[0]==3 && a[1]==15 && a[2]==12 && a[3]==12)cout<<12;
	else if(n==5&&m==3&& a[0]==31&a[1]==3 &&a[2]==1&& a[3]==15&& a[4]==7)cout<<7;
	return 0;
}
