#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,num,h;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int a;
    	char c;
    	cin>>a>>c;
    	for(int j=1;j<=a;j++)
    	{
    		s[num]=c;
			num++;
			h++;
		}
	}
    int ans=0;
    for(int i=0;i<num/2;i++)
    {
    	h--;
    	if(s[i]!=s[h])
    	{
    		ans++;
		}
	}
	cout<<ans;
	
    
	return 0;
}

