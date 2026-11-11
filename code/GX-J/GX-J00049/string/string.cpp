#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct str
{
	unsigned long long num;
	char cha;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<str> stri(n);
	vector<char> strin;
	unsigned long long sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>stri[i].num>>stri[i].cha;
		sum+=stri[i].num;
		for(unsigned long long j=0;j<=stri[i].num;j++)
		{
			strin.push_back(stri[i].cha);
		}
	}
	int ans=0;
	for(unsigned long long i=0;i<sum/2;i++)
	{
		if(strin[i]!=strin[strin.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
