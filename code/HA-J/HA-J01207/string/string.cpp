#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,k[N],ans;
string s;
char a;
int check(string x,long long l)
{
	int y=x.size();
	if(x[l]!=x[y-1-l])return 0;
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k[i]>>a;
		s+=a;
	}
	long long y=s.size()/2;
	for(int i=0;i<y;i++)
	{
		string l;
		y=s.size()/2;
		int f=s.size();
		if(!check(s,i))
		{
			ans+=min(k[i],k[f-i-1]);
			if(k[i]>k[f-i-1])
			{
				k[i]-=k[f-i-1];
				for(int j=0;j<f-1;j++)
				l+=s[j];
			}
			else if(k[i]==k[f-i-1])
			{
				for(int j=1;j<f-1;j++)
				l+=s[j];
			}
			else if(k[i]<k[f-i-1])
			{
				k[f-i-1]-=k[i];
				for(int j=1;j<f;j++)
				l+=s[j];
			}
			i=0;
		}
		else
		{
			
			if(k[i]>k[f-i-1])
			{
				k[i]-=k[f-i-1];
				for(int j=0;j<f-1;j++)
				l+=s[j];
			}
			else if(k[i]==k[f-i-1])
			{
				for(int j=1;j<f-1;j++)
				l+=s[j];
			}
			else 
			{
				k[f-i-1]-=k[i];
				for(int j=1;j<f;j++)
				l+=s[j];
			}
			i=0;
		}
		s=l;
	}
	cout<<ans;
	return 0;
} 
