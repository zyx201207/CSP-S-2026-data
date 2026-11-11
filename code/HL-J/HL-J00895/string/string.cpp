#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,cnt=0;
    bool flat=true;
    string c;
    cin >>n;
    cin >> a>>c;
    string s=c;
    string m=c;
    for(int i=2; i<=a;i++)
    {
    	s+=c;
	}
    for(int i=2;i<=n;i++)
    {
    	cin >> a>>c;
    	if(c!=m)
    	{
    		flat=false;
		}
    	for(int i=1;i<=a;i++)
    	{
    		s+=c;
		}
	}
    int l1=s.size();
    int l2=l1/2;
    for(int i=0; i<l2;i++)
    {
    	if(s[i]!=s[l1+1-i])
    	{
    		cnt++;
		}
	}
    if(flat)
    {
    	cout << 0;
	}
	else{
		cout <<cnt;
	}
    return 0;
}
