#include<bits/stdc++.h>
using namespace std;
long long n;
char s_[2147483647];
long long a,sum,q;
char p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>p;
		for(int i=1+q;i<=a+q;i++)
		{
			s_[i]=p;
		}
		q+=a;
	}
	for(int i=1;2*i<=q;i++)
	{
		if(s_[i]!=s_[q-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
		    return 0;
	    }

