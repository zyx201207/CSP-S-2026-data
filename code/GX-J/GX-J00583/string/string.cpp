#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string m[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char b;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s[j]=b;
            cout<<s[j];
        }
    }

    return 0;
}
