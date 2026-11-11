#include<bits/stdc++.h>
using namespace std;
int N=1e5+10;
int  panduan(char s[N],int k)
{
	if(k%2==0)
	{
		for(int i=0;i<k/2;i++)
		{
			if(s[i]==s[k-i-1]) 
			{
				continue;
			}
			else
			{
				return false;
				break;
			}
		}
		return true;
	}
}
int main(){
	int n,k=0;
	char s[N];
	cin>>n;
	int a[n];
	char b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b;
		for(int j=0;j<a[i];j++)
		{
			s[k]=b;
			k++;
		}
	}
	for(int i=0;i<k;i++)
	{
	cout<<s[i];	
	}
	for(int i=0;i<k;i++)
	{
	cout<<panduan(s[i]);
	}
	return 0;
}
