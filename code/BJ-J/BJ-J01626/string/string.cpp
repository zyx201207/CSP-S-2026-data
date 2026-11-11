#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[200005]={};
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s;
        if(s[0]==s[1]==s[i])
        {
            cout<<0;
            return 0;
        }
    }
    return 0;
}
