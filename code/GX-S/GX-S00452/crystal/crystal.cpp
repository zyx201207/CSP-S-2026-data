#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#define ll long long 
#define MARCH 500001
using namespace std;
ll read()
{
	char ch = 0;
	bool flag = 0 ;
	ll x = 0 ;
	//cout<<3;
	while (ch > '9' || ch < '0')
	{
		ch = getchar();
		if (ch == '-')
			flag = 1 ;
	}
	//cout<<1;
	
	while ('0' <= ch && ch <= '9')
	{
		//cout<<'%'<<ch<<'%'<<endl ;
		x = x * 10 + (ch - '0');
		ch = getchar();
		
	}
	
	//cout<<2;
	if(flag == 1)
		x = -x;
	return x ;
}
void write(ll x)
{
	if(x<0) {putchar('-');x=-x;}
	if(x<10) putchar(x+'0');
	if(x>=10) {write(x/10); putchar(x%10+'0');}
	return ;
}
ll n , m , ans , cost;
ll a[MARCH];
int main ()/////////////////////////////check input!!
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//cout << 4 ;
	n = read();
	//cout << 5 ;
	m = read();
	//write(n);
	//putchar('\n');
	//write(m);
	//putchar('\n');
	for(int i=1 ; i<=n ; i++)
		a[i] = read();
	sort(a+1,a+n+1);
	ans = 1 ; cost = 0 ;
	for(int i=2;i<=n;i++)
	{
		if(( a[i] - a[i-1] ) * ( i - 1 ) + cost <= m)
		{
			cost += ( a[i] - a[i-1] ) * ( i - 1 );
			ans ++ ;
		}
		else break;
	}
	write(ans);
	//cout << MARCH<<" ";
	//cout << endl ;
	//for(int i=1;i<=n;i++)
	//	cout<< a[i] <<" ";
	return 0;
}
