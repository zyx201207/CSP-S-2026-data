#include<bits/stdc++.h>
using namespace std;
int n;
long long m,base,need,mxn,mmm;
vector<long long> a;
vector<long long> b;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
		//cout<<temp<<endl;
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
	{
		//cout<<a[i];
		b.push_back(a[n-1]-a[i]);
	}
	for(int i=n;i>0;i--)
	{
		need=0;
		mmm=0;
		for(int j=i-1;j>=0;j--)
		{
			need+=b[j]-b[i];
			if(need<m)
			{
				mmm++;
			}
			if(need==m)
			{
				mmm++;
				break;
			}
			if(need>m)
			{
				break;
			}
		}
		//cout<<mxn<<' ';
		mxn=max(mxn,mmm);
	}
	cout<<mxn+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
