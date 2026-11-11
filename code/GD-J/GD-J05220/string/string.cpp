#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans;
int v=1;
char l;
string p,s1,s2;
void check1()//check if a right string 
{
	int b=1;
	if((v-1)%2==0)
	{
		for(int i=1;i<=(v-1)/2;i++)s1[i]=p[i];
		for(int i=v-1;i>=(v-1)/2+1;i--)
		{
			s2[b]=p[i];
			b++;
		}
	}
	else
	{
		for(int i=1;i<=(v-1)/2;i++)s1[i]=p[i];
		for(int i=v-1;i>=(v-1)/2+2;i--)
		{
			s2[b]=p[i];
			b++;
		}
	}
	for(int i=1;i<=b-1;i++)
	{
		if(s1[i]!=s2[i])
		{
			for(int j=1;j<=b-1;j++)
			{
				if(s1[j]!=s2[j])
				{
					ans++;
					
				}
			}
//			cout<<s1[2]<<" "<<s2[1];
			cout<<ans;
			
			return;
		}
		
	}
	cout<<0;
	return;
	/*if(s1==s2)return true;
	else return false;*/
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin >> m;
		cin >> l;
		if(n==1&&m==1)
		{
			cout<<0;
			return 0;	
		}
		
		for(int j=1;j<=m;j++)//load the string
		{
			p[v]=l;
			v++;
		}
	}
	check1();

	
	
	return 0;
} 
