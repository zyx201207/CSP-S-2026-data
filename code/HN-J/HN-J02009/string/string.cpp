#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string l;
	char t;
	long long n,sum=0,c,dp=0,sum2=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		sum+=c;
		cin>>t;
		for(int j=dp;j<c+dp;j++)
		{
			l[j]=t;
		}
		dp+=c;
	}
	//现在l是这个回文数，sum是他的总个数
	if(sum==1)
	{
		cout<<0;
		return 0; 
	}
	for(int i=0;i<sum/2;i++)
	{
			if(l[i]!=l[sum-1-i])
			{
				sum2++;
			}
	} 	
	cout<<sum2;
	return 0;
} //ccfnb ccfnb 6 2 1000000000 a 3 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
