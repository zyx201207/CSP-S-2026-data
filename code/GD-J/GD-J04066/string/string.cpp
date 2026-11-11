#include<iostream>
using namespace std;
string s;
int n,ans,sum,xi;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>xi>>x;
		ans+=xi; 
		for(int j=0;j<xi;j++)
		{
			s+=x;
		}
	}
	if(ans%2==1)
	{
		int mid=ans/2;
		for(int i=0;i<mid;i++)
		{
			if(s[i]!=s[n-i+1])	
				sum++;
		}
	} 
	else
	{
		int mid=ans/2;
		for(int i=0;i<=mid;i++)
		{
			if(s[i]!=s[n-i+1])	
				sum++;
		}
	}
	cout<<sum;
	return 0;
}
