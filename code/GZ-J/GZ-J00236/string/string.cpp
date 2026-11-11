//鲁卓然 贵阳市第18中学 GZ-J00236 
#include<bits/stdc++.h>
using namespace std;
int const N = 2e5+5; 
struct node
{
	long long a;
	char c;
};
long long upe2(long long a)
{
	if(a % 2 == 1) return (a - 1) / 2 + 1;
	else return a / 2;
}

char idxof(int ws,node aa[],int n)
{
	for(int i = 1 ; i <= n ;  i++)
	{
		long long m = aa[i].a;
		if(ws - m <= 0) return aa[i].c;
  		else ws -= m;
	}
}
char f(int ws,node aa[],int n)
{
	for(int i = n ; i >= 1 ; i--)
	{
		long long m = aa[i].a;
		if(ws - m <= 0) return aa[i].c;
  		else ws -= m;
	}
}
long long hw(node aa[],int n)
{
	long long cnt = 0;
	long long zkc = 0;
	for(int i = 1 ; i <= n ; i++) zkc += aa[i].a;
	for(int ws = 1 ;  ws <= upe2(zkc) ; ws++)
	{
	    if(f(ws,aa,n) != idxof(ws,aa,n)) cnt++;
	} 
	return cnt;
} 
node aa[N];
int main()
{
 	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	for(int i = 1 ; i <= n; i++) cin>>aa[i].a>>aa[i].c;
	cout<<hw(aa, n);
	return 0;
}
