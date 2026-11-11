#include<bits/stdc++.h>
using namespace std;
vector<long long>aa;
vector<long long>a;
vector<long long>b;
vector<long long>c;
vector<long long>d;
vector<long long>f;
int main()
{
	long long n,m;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		aa.push_back(x);
	}
	for(long long i=0;i<n;i++)a.push_back(aa[n-i-1]);
	for(long long i=0;i<m;i++)
	{
		c.push_back(m-i);
		//cout<<m-i<<" ";
		f.push_back(0);
	}
	//long long ans=0;
	for(long long i=0;i<n;i++)
	{
		//b=a;
		b=vector<long long>();
		d=vector<long long>();
		for(long long j=0;j<n-i;j++)b.push_back(a[j]);
		for(long long j=0;j<(long long)b.size();j++)
		{
			//cout<<b.size()-j-1;
			long long e=b[(long long)b.size()-j-1];
			//cout<<e<<" \n";
			
		    bool flag=0;
		    for(long long z=0;z<(long long)d.size();z++)
		    {
		    	if(d[i]==e)
		    	{
		    		flag=1;
		    		for(long long ii=z;ii<d.size();ii++)
		    		{
		    			d.pop_back();
					}
					d.push_back(e);
					break;
				}
			}
			if(flag)
			{
				d.push_back(e);
			}
			b.pop_back();
		}
		//cout<<"\n";
		//bool flag1=0;
		for(long long j=0;j<d.size();j++)f[d[j]]++;//if(b[j]==i+1){flag1=1;break;}
		//if(flag1)ans++;
	}
	for(long long i=0;i<m;i++)cout<<f[i]<<" ";
	//4 3 1 2 1 3
	return 0;
}
