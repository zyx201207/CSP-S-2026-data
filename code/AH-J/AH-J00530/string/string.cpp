#include<bits/stdc++.h>
using namespace std;
string s;
long long a,sum=0;
int n;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long l=s.size();
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
    return 0;
}    
