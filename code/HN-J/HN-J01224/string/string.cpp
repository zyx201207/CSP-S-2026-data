#include<bits/stdc++.h> 
using namespace std;
char l['0'];
int a[100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int r,ans=0;
	cin>>r;
	char t['0'];
	for(int i=1;i<=r;i++)
	{
		cin>>a[i];
	    cin>>l[i];
    } 
    for(int i=r;i>=1;i--)
    {
    	if(i!=l[i])
    	{
    		i=l[i];
    		ans+=a[i];
		}
	}
	cout<<ans;
}
