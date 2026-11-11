#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
bool cheak(long long cnt,long long m)
{
	long long s=m,i=0;
	for(i=0;v[i]<cnt&&i<v.size();i++)
	{	//cout<<v[i]<<" "<<s<<endl;
			s-=(cnt-v[i]);		
	}
	//cout<<endl;
	if(s>=0) return 1;
	else if(s<0) return 0;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long l=544454554454,r=-544454554454;
	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		v.push_back(a);
		r=max(a,r);
		l=min(a,l);
	}
	r+=m;
	sort(v.begin(),v.end());
	//cout<<l<<' '<<r<<" "<<endl;
	while(l<r)
	{//cout<<endl;
		long long mid = (l+r)/2;
		bool q=cheak(mid,m);
		if(q)
			l=mid+1;
		else
			r=mid-1;

	}		
	
	long long ans=0,s=m;
	for(int i=0;i<v.size();i++)
	{
		//cout<<(r-v[i])<<" "<<s<<" "<<ans<<endl;
		if(v[i]>r) break;
		if(s-(r-v[i])>=0) 
		{
		s=s-(r-v[i]);
		ans++;	
		}
	}

	cout<<ans;
}
