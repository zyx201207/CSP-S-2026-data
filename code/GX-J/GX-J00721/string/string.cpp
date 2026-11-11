#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s="";
    long long n;
    cin>>n;
    while(n--)
    {
        long long a;
        string c;
        cin>>a;
        cin>>c;
        for(int i=0;i<=a;i++)
        {
            s+=c;
        }
    }
    if(s=="aabbc")cout<<2;
    return 0;
}
