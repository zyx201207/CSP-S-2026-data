#include<bits/stdc++.h>
using namespace std;
string s[10000005];
int n,l,num,x;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l>>x;
        for(int i=1;i<=l;i++)
        {
            s[i]+=x;
        }

    }
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[n-1-i])
        {
            continue;
        }
        else
        {
            num++;
        }
    }
    cout<<num;
    return 0;
}
