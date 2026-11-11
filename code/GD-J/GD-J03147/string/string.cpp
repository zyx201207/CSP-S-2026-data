#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	string S;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		string s;
		scanf("%d",&a);
		cin>>s;
		for(int j=0;j<a;j++)S+=s;
	}
	long long mid=S.size()/2;
	long long j=S.size()-1;
	for(int i=0;i<mid;i++)
	{
		if(i==j)
		{
			break;
		}
		if(S[i]!=S[j])
		{
			S[j]=S[i];
			sum++;
		}
		j--;
	}
	printf("%lld\n",sum);
	return 0;
}

