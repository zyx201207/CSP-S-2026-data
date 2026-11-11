#include<bits/stdc++.h> 
using namespace std;
#define int long long
	string c,d,e;
	long long n,a,b=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
 while(n>0)
{
	
				
		cin>>a>>d;
		while(a>0)
		{
				c=c+d;
				a--;
	
        }
	
	n--;
	}
	
	for(int i=c.size()-1;i>=0;i--)
		{
			e[c.size()-i-1]=c[i];
		}
			for(int i=0;i<c.size();i++)
		{
			if(c[i]!=e[i])
			{
				b++;
			}
		}
		cout<<b/2;
	return 0;
} 
