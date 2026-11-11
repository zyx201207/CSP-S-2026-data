#include<bits/stdc++.h>
using namespace std;
#define inr long long
#define endl '\n'
inr a[500500],n,m;
inr wat(inr q,inr w)
{
	inr wq=0,s=0;
	for(int i=w;i>=0;i--)
	{
		if(a[i]>q)
			break;
		if(wq+q-a[i]>m)
			break;
		s++;
		wq+=q-a[i];
	}
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<inr> as,sa;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			sa.push_back(i);
			as.push_back(a[i]);
		}
	}
	inr l=0,r=as.size()-1,ans=0;
	for(int i=0;i<as.size();i++)
	{
		inr mids=wat(as[i],sa[i]);
		if(mids>ans)
		{
			ans=mids;
			//cout << mids << ' ' << i << endl;
		}
	}
	cout << ans;
	return 0;
}
