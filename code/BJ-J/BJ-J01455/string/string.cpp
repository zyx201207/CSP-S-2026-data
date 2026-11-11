#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s=NULL;
    for(int i=1;i<=n;i++)
    {
        char c;
        int m;
        cin>>m;
        cin>>c;
        for(int j=1;j<=m;j++)
            s+=c;
    }
    int sum=0,h=s.length();
    for(int i=h/2;i<=h;i++)
    {
        if(s[i]!=s[i-h/2])
            sum++;
    }
    cout<<sum;
    return 0;
}
