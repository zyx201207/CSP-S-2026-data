#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll a[N],qz[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cm=0;
	for(int i=2;i<=n;i++)
	{
		qz[i-1]=a[i]-a[i-1];
		cm+=qz[i-1];
	}
	ll t=1,w=n-1;
	while(cm>m)
	{
		if(qz[t]>qz[w])
		{
			cm-=qz[t];
			t++;
		}else
		{
			cm-=qz[w];
			w--;
		}
	}
	cout<<w-t+2;
	return 0;
	//wdfk啊一点思路没有 
	
	
	//int year,month,days;
	//year=2026;
	//month=10;
	//days=31;
	//day+=3;
	//month+=(days/31);
	//days%31;
	//(经过一堆繁琐的流程反正是把int变成string);
	//string birthday=year+month+days;
}
