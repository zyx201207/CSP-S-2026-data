//GZ-J00422,贵阳市南明区华麟学校,张柏塾
#include <bits/stdc++.h>
using namespace std;
int a[200010];
string s=" ";
int main()
{
    freopen("string"r",stdin);
    freopen("string,"w",stdout);
    int n,num=0,sum=0;
    string b;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b;
        for (int j=1;j<=a[i];j++)
        {
            s+=b;
            num++;
        }
    }
    for (int i=0;i<num/2;i++)
    {
        if(s[i]!=s[num-1-i])
        {
            s[num-1-i]=s[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
