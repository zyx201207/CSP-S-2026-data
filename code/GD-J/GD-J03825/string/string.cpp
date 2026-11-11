#include <bits/stdc++.h>
using namespace std;
string s;
int n;
string rev(string t)
{
    string q=t;
    int p=t.size()-1;
    for(int i=0;i<=p;i++)
    {
        t[i]=q[p-i];
    }
    return t;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        char l;
        cin>>l;

        for(int j=1;j<=x;j++)
        {
            s=s+l;
        }
    }
    //cout<<s;
    string t=s.substr(s.size()/2);
    t=rev(t);
    //cout<<s<<endl<<t;
    int cnt=0;
    for(int i=0;i<=t.size()-1;i++)
    {
        if(s[i]!=t[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
