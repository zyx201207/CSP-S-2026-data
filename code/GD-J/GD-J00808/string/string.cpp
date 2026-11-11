#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    char a;
    string s="";
    for(int i=1;i<=n;i++)
    {
    	int num;
    	cin>>num>>a;
    	for(int j=1;j<=num;j++)
    	{
    		s+=a;
		}
	}
	int j=s.size();
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[j])
		{
			sum+=1;
		}
		j--;
	}
	cout<<sum;
	return 0;
} 
