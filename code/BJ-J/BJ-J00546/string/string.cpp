#include<bits/stdc++.h>
using namespace std;
vector<char> ch;
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long size=0;
	for(int i=0;i<n;i++)
	{
		long long t;
		char c;
		cin>>t>>c;
		size+=t;
		for(int j=0;j<t;j++)
			ch.push_back(c);
	}
	for(int i=0;i<size/2;i++)
	{
		if(ch[i]!=ch[ch.size()-i-1])
		{
			cout<<ch[i]<<" "<<ch[ch.size()-i-1]<<endl;
			sum++;
		}
			
	}
	cout<<sum;
    return 0;
}
