#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int n,m;
long long getans(int k)
{
	//cout<<"候选元素数量"<<a.size()<<endl;
	long long ans;
	for(;k/=2;)
	{
		vector<int> id;
		int cnt=0;
		int nn=a.size();
		for(int i=0;i<nn;i++)
		{
			//cout<<a[i]<<"&k="<<(a[i]&k)<<" "<<"k="<<k<<endl;
			if((a[i]&k)>=k)
			{
				//cout<<"cnt++;\n";
				cnt++;
				id.push_back(i);
			}
		}
		//cout<<"k="<<k<<" cnt="<<cnt<<endl;
		vector<long long> ttmp;
		if(cnt>=m)
		{
			ans=a[id[0]];
			for(int i=1;i<m;i++)
			{
				ans&=a[id[i]];
				ttmp.push_back(a[id[i]]);
			}
			for(int i=0;i<cnt;i++)
			{
				ttmp.push_back(a[id[i]]);
			}
			a=ttmp;
		}
		if(cnt>m)
		{
			return max(ans,getans(k));
		}
		else if(cnt==m)
		{
			return ans;
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<getans(1<<30)<<endl;
	return 0;
}
