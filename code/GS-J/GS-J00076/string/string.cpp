#include<bits/stdc++.h>
using namespace std;
string s;
int sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>s;
    int a=s.size()/2;
    for(int i=1;i<=a;i++)
    {
        if(s[i]==s[i+a])
        {
            sum+=0;
        }
        else
        {
                sum+=1;
        }
    }
    cout<<sum;
    return 0;
}
