#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct A{
	long long a;
	char x;
}a[N];
int n,r=1,l=0;
long long num=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].x;
	}
	l=n;
	while(r<l)
	{
		int ls_a_r=a[r].a;
		char ls_x_r=a[r].x;
		int ls_a_l=a[l].a;
		char ls_x_l=a[l].x;
		r++;
		l--;
		if(ls_x_r!=ls_x_l)
		{
			if(ls_a_r>ls_a_l)
			{
				num+=ls_a_l;
				r--;
				a[r].a=ls_a_r-ls_a_l;
			}
			if(ls_a_r==ls_a_l) num+=ls_a_r;
			if(ls_a_r<ls_a_l)
			{
				num+=ls_a_r;
				l++;
				a[l].a=ls_a_l-ls_a_r;
			}
		}
		else
		{
			if(ls_a_r>ls_a_l)
			{
				r--;
				a[r].a=ls_a_r-ls_a_l;
			}
			if(ls_a_r<ls_a_l)
			{
				l++;
				a[l].a=ls_a_l-ls_a_r;
			}
		}
	}
	cout<<num;
	return 0;
}
