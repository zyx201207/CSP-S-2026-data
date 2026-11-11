#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long f[500005];
long long n = 0;
int sy = 0;//剩余操作数 


bool can(long long i,long long add)//i表示操作次数,add表示增加的水晶a[add] 
{
	long long que = 0;//que:缺少能量数 
	if(i <= 0) return false;
	for(long long j = 1;j <= add;j++)
	{
		que += (a[add] - a[j]);
	}
	if(i >= que){
		sy -= i;
		return true;
	}
	else return can(i-1,add);
}



int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long pgz = 0;//能量数平均值 
	unsigned long long m;
	cin>>n>>m;//n为水晶数量，m为操作次数 
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sy = m;
	sort(a+1,a+n+1);
	
	f[1] = 1;
	
	for(int i = 2;i <= n;i++)//下标i以前的水晶 
	{
		if(can(m,i))
		{
			f[i] =f[i-1] + 1;
		}
		else{
			f[i] = f[i-1];
		}
	}
	
	cout<<f[n];
	return 0;
	
	
	
}
