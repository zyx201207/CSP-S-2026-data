#include<bits/stdc++.h>//头文件 
using namespace std;

struct node
{
	int a;
	char s;
};
node p[200005];
string as, as1, as2, as3;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans = 0;
	//输入 
	cin >> n;
	for(int i=1; i<=n; i++)//字符输入 
	{
		cin >> p[i].a >> p[i].s;
	}
	for(int i=1; i<=n; i++)//转化为字符串
	{  
		for(int j=1; j<=p[i].a; j++)
		{
			as += p[i].s;
		}
	}
	int m = as.size()/2; //减半 
	if(as.size()%2 == 1)
	{
		as3 = as[m]; //长度为单数时的中间字符 
	}
	for(int i=0; i<m; i++) //前半段 
	{
		as1 += as[i];
	}
	for(int i=as.size(); i>m+1; i--) //后半段（倒过来） 
	{
		as2 += as[i];
	}
	if(as1 == as2)
	{
		cout << 0;
		return 0;
	} 
	else
	{
		for(int i=0; i<as1.size(); i++)
		{
			if(as1[i] != as2[i])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
