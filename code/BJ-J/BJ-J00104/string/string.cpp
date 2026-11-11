#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	string s;
	char t;
	for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        t=y;
        for(int j=1;j<=x;j++)
        {
            s+=y;
        }
    }
    int cnt=0;
    bool flag=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t)
        {
            flag=false;
            break;
        }
    }
    if(flag==true)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<=s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
