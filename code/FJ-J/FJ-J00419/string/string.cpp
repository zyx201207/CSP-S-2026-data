#include<bits/stdc++.h>
using namespace std;
int n,s1=0;
char s[1000000000];
long long zs=0;
int ans=0;
void css()
{
	//cout<<'0';
	if(zs<=10000000000)
	{
		for(int i =0;i<zs/2;i++)
		{
			if(s[i]!=s[zs-i])
			{
				ans++;
			} 
		}
		cout<<ans;
	} 
	else
	{
		cout<<zs/2;
	}
		
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n],cs=0;
	
	char b[n],y;
	for(int i =0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		char u =b[i];
		if(i ==0){
			y = u;	
		}
		if(u==y){
			cs++;	
		} 
		zs+=a[i];
	}
	if(cs==n){
		cout<<0;
		return 0;	
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j =0;j<a[i];j++)
		{
			s[s1]=b[i];
			s1++; 
		}
	 } 
	 //cout<<0;
	css();
	//cout<<ans;
	return 0;
}
