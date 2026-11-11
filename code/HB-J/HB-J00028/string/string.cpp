
#include<bits/stdc++.h>
using namespace std;
int a[200020];
char ch[200020];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
         cin>>a[i]>>ch[i];
         for(int j=1;j<=a[i];j++)
            s+=ch[i];
    }
    int len=s.size();
    for(int i=0;i<=(len-1)/2;i++)
    {
        if(s[i]!=s[len-1-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
