#include<bits/stdc++.h>
using namespace std;
struct stu{
    long long a;
    char c;
}s[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=s[i].a;
    }
    int k=0;
    if(sum%2!=0)
        k=1;
    sum/=2;
    string ss;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=s[i].a;j++)
        {
            ss+=s[i].c;
        }
    }

    string ss1,ss2;
    for(int i=0;i<sum;i++)
    {
        ss1+=ss[i];
    }
    for(int i=sum+k;i<sum*2+k;i++)
    {
        ss2+=ss[i];
    }

    int cnt=0;
    for(int i=0;i<sum;i++)
    {
        if(ss1[i]!=ss2[i])
            cnt++;
    }
    cout<<cnt;

    return 0;
}
