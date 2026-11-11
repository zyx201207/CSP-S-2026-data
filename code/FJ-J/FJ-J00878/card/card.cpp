#include<bits/stdc++.h>
using namespace std;
long long n,a,t[200005],d,x,ans;
string c,b,s[200005]; 
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	cin>>a;
	cin>>c;
	b=c;
	t[d]+=a;
	s[d]=c;
	for(int i=1;i<n;i++)
	{
		cin>>a>>c;
		if(b==c) t[d]+=a;
		else t[++d]+=a;
		s[d]=c;
		b=c;
	}
	for(int i=d;i>=d/2;i--)
	{
		if(i==x) break;
		if(s[i]!=s[x]){
			if(t[i]<t[x]){
				t[x]-=t[i];
				ans+=t[i];
				continue;
			}else{
				t[i]-=t[x];
				ans+=t[x];
				x++;
				i++;
			}
		}
		else
		{
			if(t[i]<t[x])
			{
				t[x]-=t[i];
				continue;
			}
			else{
				t[i]-=t[x];
				x++;
				i++;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
