#include<bits/stdc++.h>
using namespace std;
string a="";
int n,s,len;
int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int q;
        char w;
        cin>>q>>w;
        len+=q;
        while(q--) a+=w;
    }
    for(int i=0;;i++)
    {
        if(a[i]!=a[len-1-i]) s++;
        if(i>=len-1-i) break;
    }
    cout<<s;
    return 0;
}
