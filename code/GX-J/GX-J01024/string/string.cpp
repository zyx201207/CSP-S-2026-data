#include <bits/stdc++.h>

using namespace std;

string s;
string s2,s3;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        for(int i=0;i<a;i++)
        {
            s=s+c;
        }
    }

    if(s.size()%2==0)
    {
        s2=s.substr(0,(s.size()+1)/2);
        s3=s.substr((s.size()+1)/2,(s.size()+1)/2);
    }
    else
    {
        s2=s.substr(0,(s.size()+1)/2);
        s3=s.substr((s.size()-1)/2,(s.size()+1)/2);

    }
    long long cnt=0;
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]!=s3[s3.size()-1-i])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
