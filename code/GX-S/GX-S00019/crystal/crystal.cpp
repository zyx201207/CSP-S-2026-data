#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
int conculate(vector<long long> cry,int mm,int i)
{
	int ans=0;
	for(int j=0;j<n&&mm>=0;j++)
	{
		if(cry[j]>cry[i])
		{
			--cry[j];
			--j;
			--mm;
		}
		else if(cry[j]<cry[i])
		{
			++cry[j];
			--j;
			--mm;
		}
		else
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> cry(n);
	for(int i=0;i<n;i++)
	{
		cin>>cry[i];
	}
	int answer=0;
	for( long long i=0;i<n;i++)
	{
		answer=max(answer,conculate(cry,m,i));
	}
	cout<<answer;
	return 0;
}
