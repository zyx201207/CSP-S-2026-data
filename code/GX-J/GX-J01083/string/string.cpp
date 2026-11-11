#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,d=0;
    char a;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m>>a;
        for(int l=0;l<m;l++)
        {
            s+=a;
        }
    }
    for(int i=0;i<(s.size()+1)/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            d++;
        }
    }
    cout<<d;
    return 0;
}
