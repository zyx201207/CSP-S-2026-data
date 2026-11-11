#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int a,n;
    int m=0;
    char c;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a>>c;
        for(int j=n;j>=1;++j)
        {
            if(s[i]==s[j])
            {
                cout<<"0";
            }
            else
            {
                m++;
                cout<<m;
            }
        }
    }
    return 0;
}
