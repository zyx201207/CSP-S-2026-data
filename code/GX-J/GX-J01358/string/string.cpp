#include<bits/stdc++.h>
using namespace std;
string s,a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=1,q,sum=0;
    cin>>n;file:///home/noilinux/gx-J01358/and/and.cpp

    for(int i=1;i<=n;i++)
    {
        cin>>q>>a;
        for(int j=1;j<=q;j++)
        {
            s+=a;
        }
    }

for(int i=0,j=s.size()-1;i<=s.size()/2;i++,j--)
    {
        if(s[i]!=s[j])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
