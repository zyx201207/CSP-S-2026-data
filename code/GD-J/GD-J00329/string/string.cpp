#include<bits/stdc++.h>
using namespace std;
int n;
int e=1,t=0;
string a,b;
long long sum=0;
int ck(string q)
{
	string b;
	for(int i=q.size()-1;i>=0;i--)
	{
		char w=q[i];
		b+=w;
	}
	if(q==b) return 1;
	else return 2;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","out",stdout);
	cin>>n;
	
	for(int j=0;j<n;j++)
	{
		long long k;
		cin>>k;
		char s;
		cin>>s;
		
	    for(int i=t;i<t+k;i++)
	    {
	    	a+=s;
	    	if(j!=0&&a[i]!=a[i-1]) 
			{
				e=0;
				sum+=k;
			}
		}
		t+=k;
	}
	if(e==1||ck(a)==1) 
	{
		cout<<'0';
		return 0;
	}	
	else if(sum>=1000000000) cout<<sum;
	else 
	{
		if(ck(a)==1) 
		{
			cout<<'0';
			return 0;
		}
		long long ans=0;
		while(ck(a)!=1){
			for(int i=a.size()-1;i>=0;i--) 
			{
				char l=a[i];
				b+=l;
			}
		    for(int i=0;i<a.size();i++)
		    {
		    	if(a[i]!=b[i])
		    	{
		    		a[a.size()-i-1]=a[i];
		    		ans++;
					if(ck(a)==1){
					cout<<ans;
					return 0;
					}
					b.clear();
		    		break;
				}
			}
			
		}	
	}
	return 0;
}
