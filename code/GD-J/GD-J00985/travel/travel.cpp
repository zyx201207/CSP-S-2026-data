#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);bool flag=1;
	string r_t,x_t,r_s,x_s;
	cin>>r_t>>r_s>>x_t>>x_s;
	int a=stoi(r_t),b=stoi(x_t),p_a=stoi(r_s),p_b=stoi(x_s),len_a=r_s.size(),len_b=x_s.size();
	if(a!=b)
	{
		cout<<0000;
		return 0;
	}
	cout<<(a==b);
	if(p_a!=p_b)
	{
		cout<<000;
		return 0; 
	}
	if(r_s[len_a-1]<'D'&&x_s[len_b-1]<'D')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=0;
	}
	if(flag&&abs(int(r_s[len_a-1]-x_s[len_b-1]))==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
