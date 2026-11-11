#include<bits/stdc++.h>
using namespace std;
long long n,len=0;
long long k=0,ans=0;
string l,l1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a;char c;
		cin>>a>>c;
		for(long long j=i;j<i+a;j++) 
		{
			l[j]=c;
			len++;
		}
	}
	for(int i=len/2;i>0;i--)
	{
		l1[k++]=l[i];
	}
	int k=0;
	for(int i=len/2+1;i<=len;i++)
	{
		if(n%2==0)
		{
			if(l[i]!=l1[++k])
			{
				ans++;
			}
		}else{
			if(l[i]!=l1[k++])
			{
				ans++;
			}			
		}

	}
	cout<<ans;
	return 0;
}
