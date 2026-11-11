#include<bits/stdc++.h>
using namespace std;
long long n,num,sum;
char a[200005];
string str;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    sum=0;
    for(long long i=0;i<n;i++)
    {
        long long b;
        cin>>b;
        cin>>a[i];
        for(int j=0;j<b;j++)
        {
            str=str+a[i];
        }
    }
    for(long long i=str.size()-1;i>=str.size()/2;i--)
    {
        if(str[num]!=str[i])
        {
            sum++;
        }
        num++;
    }
    cout<<sum;
    return 0;
}
