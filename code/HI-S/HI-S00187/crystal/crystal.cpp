#include<bits/stdc++.h>
using namespace std;
long long _cnt=LLONG_MAX,mid;
bool srt(long long a,long long b)
{
	long long _a=max(a,mid)-min(a,mid);
	long long _b=max(b,mid)-min(b,mid);
	return _a<_b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long> v;
	for(long long i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(long long i=0;i<v.size();i++)
	{
		long long cnt=0;
		for(long long j=0;j<v.size();j++)
		{
			if(i==j)
				continue;
			if(j<i)
				cnt+=v[i]-v[j];
			else 
				cnt+=v[j]-v[i];
		}
		if(cnt<_cnt)
		{
			_cnt=cnt;
			mid=v[i];
		}
	}
	//cout<<_cnt<<" "<<mid<<endl;
	sort(v.begin(),v.end(),srt);
	//cout<<v[0]<<endl;
	long long ans=0;
	while(v.size()>0)
	{
		m-=abs(mid-v[0]);
		if(m<0)break;
		//cout<<m<<" "<<v[0]<<"\n";
		v.erase(v.begin());
		ans++;
	}
	//cout<<endl;
	cout<<ans;
	return 0;
}
