#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++)
			s+=c;
	}
	long long cnt=0;
	for(long long i=0;i<=sum/2-1;i++)
		if(s[i]!=s[sum-i-1])
			cnt++;
	cout<<cnt;
	return 0;
 } 
