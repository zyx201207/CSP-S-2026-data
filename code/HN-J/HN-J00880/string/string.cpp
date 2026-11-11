#include<bits/stdc++.h> 
using namespace std;
string s;
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int  n;
    long long l,r;
    long long ans=0;
    char c;
    cin>>n;
    for (int i=0;i<n;i++)
    {
    	cin>>a[i]>>c;
    	for (int j=1;j<=a[i];j++)
    	{
    		s+=c;
		}
	}
    l=0;
    r=s.length()-1;
    if(n==1)
    {
    	cout<<0;
    	return 0;
	}
	
	while(l<r){
		if(s[l]!=s[r])
		{
			s[r]=s[l];
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
    return 0;
}
