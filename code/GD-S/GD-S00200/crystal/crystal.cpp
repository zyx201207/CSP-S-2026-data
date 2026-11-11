#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m;
ll a[N];
struct hzh{
	//ll last,nxt;//当前值的前一种，后一种
	ll what;//当前值是什么
	ll number;//多少个 
}hu[N];
ll cnt;
ll need;
ll ans;
ll geshu;
ll cost;
ll ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	/*for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"\n";*/
	a[n+1]=INT_MAX;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]==hu[cnt].what)hu[cnt].number++;
		else
		{
			hu[++cnt].what=a[i];
			hu[cnt].number=1;
		}
	}
	/*for(int i=1;i<=cnt;i++)
	{
		cout<<hu[i].what<<" "<<hu[i].number<<"\n";
	}*/
	ll j=1;
	for(int i=1;i<cnt;i++)
	{
		//need=geshu*(hu[i].what-hu[i-1].what);
		if(geshu*(hu[i].what-hu[i-1].what)>m-cost)
		{
			while(geshu*(hu[i].what-hu[i-1].what)>m-cost)
			{
				geshu-=hu[j].number;
				cost-=(hu[i-1].what-hu[j].what)*hu[j].number;
				j++;
			}
			//cout<<i<<" "<<j-1<<"?";
			ll fanhuan=(m-cost-geshu*(hu[i].what-hu[i-1].what))/(hu[i].what-hu[j-1].what);//返还 
			//cout<<(m-cost-geshu*(hu[i].what-hu[i-1].what))<<"?";
			if(fanhuan>0)hu[j-1].number=fanhuan,j--,geshu+=hu[j].number,cost+=(hu[i-1].what-hu[j].what)*hu[j].number;
		}
		cost+=geshu*(hu[i].what-hu[i-1].what);
		geshu+=hu[i].number;
		ma=max(ma,geshu);
		//cout<<hu[i].what<<" "<<geshu<<"\n";
	}
	cout<<ma;
	return 0;
}
/*
10 5
1 1 2 2 4 4 3 5 7 8
*/
