#include<bits/stdc++.h>
using namespace std;
string s;
long long n,c,sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a;
        string s1;
        cin>>a>>s1;
        s+=s1;
        c+=a;
    }
    for(int i=0;i<c;i++)
    {
        if(s[i]!=s[c-i])sum++;
    }
    cout<<sum/2;
    return 0;
}

