#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
ll a[N];
char c[N];
ll sum=0;
int mid=1;
ll ans=0;
void diff()
{
	int p=1;
	ll tsum=(sum+1)/2;
	while(tsum)
	{
		if(a[p]>tsum)
		{
			a[p]--;
			break;
		}
		tsum-=a[p];
		p++;
	}
	sum--;
}
void solve()
{
	int Lp=1,Rp=n;
	while(Lp<=mid and Rp>mid)
	{
		while(Lp<=mid and a[Lp]==0)
			Lp++;
//		cout<<"1========== "<<Lp<<"\n";
		if(Lp>mid)
			break; 
		while(Rp>mid and a[Rp]==0)
			Rp--;
//		cout<<"2========== "<<Rp<<"\n";
		if(Rp<=mid)
			break;
//		cout<<a[Lp]<<" "<<c[Lp]<<"- !?vs?! -"<<a[Rp]<<" "<<c[Rp]<<"\n";
		if(a[Lp]>a[Rp])
		{
			a[Lp]-=a[Rp];
			if(c[Lp]!=c[Rp])
				ans+=a[Rp];
			a[Rp]=0;
		}
		else if(a[Lp]<a[Rp])
		{
			a[Rp]-=a[Lp];
			if(c[Lp]!=c[Rp])
				ans+=a[Lp];
			a[Lp]=0;
		}
		else
		{
			if(c[Lp]!=c[Rp])
				ans+=a[Lp];
			a[Lp]=0,a[Rp]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
//	cout<<sum<<"\n";
	if(sum&1)
		diff();
	sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	ll ttt=sum/2;
	while(ttt)
	{
		if(a[mid]>ttt)
		{
			if(a[mid]-ttt-ttt>=0)
				a[mid]-=ttt,a[mid]-=ttt;
			else
			{
				ll dif_ttt=a[mid]-ttt;
				a[mid]-=dif_ttt,a[mid]-=dif_ttt;
			}
			break;
		}
		ttt-=a[mid];
		if(!ttt)
			break;
		mid++;
	}
	ll sss=0;
	for(int i=1;i<=n;i++)
		sss+=a[i];
	mid=1;
	ttt=sss/2;
	while(ttt)
	{
		if(a[mid]>ttt)
		{
			if(a[mid]-ttt-ttt>=0)
				a[mid]-=ttt,a[mid]-=ttt;
			else
			{
				ll dif_ttt=a[mid]-ttt;
				a[mid]-=dif_ttt,a[mid]-=dif_ttt;
			}
			break;
		}
		ttt-=a[mid];
		if(!ttt)
			break;
		mid++;
	}
//	cout<<mid<<"\n";
	solve();
	cout<<ans;
	return 0;
}

