#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0,len=0,ans=0;
struct str
{
	int l;
	char c;	
}s[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].l>>s[i].c;
		sum+=s[i].l;
	}	
	for(int i=1,j=n,res=0;len<sum/2;i++)
	{
		int t=s[i].l;
		if(len+t>=sum/2)	
			t=sum/2-len;
		len+=t;
		if(res)
		{
			int mi=min(res,t);//aabbc
			ans+=mi*(s[i].c!=s[j].c);
			t-=mi,res-=mi;
			if(!res)
				j--;
			else
				continue; 
		}
		while(t-s[j].l>=0)
		{
			ans+=s[j].l*(s[i].c!=s[j].c);
			t-=s[j].l;
			j--;	
		}
		ans+=t*(s[i].c!=s[j].c);
		res=s[j].l-t;
	}
	cout<<ans;
	return 0;
} 
