#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long num=0;
    string s;
    while(n--)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int i=num;i<num+a;i++)
        {
            s[i]=c;
            //cout<<c<<endl;
        }
        num+=a;
    }
    //cout<<num<<endl;
    string s2;
    long long ans1=0,ans2=0,t=0;
    if(num%2==0)
    {
        t=(num/2);
    }
    else
    {
        t=(num/2)+1;
    }
    //cout<<t<<endl;
    long long sum=0;
    for(long long i=num-1;i>=0;i--)
    {
        s2[sum]=(char)s[i];
        //cout<<s2[sum]<<" "<<s[i]<<endl;
        sum++;
    }
    long long ans=0;
    //cout<<ans<<endl;
    for(int i=0;i<t;i++)
    {
        if(s2[i]!=s[i])
            ans1++;
        //cout<<ans<<endl;
    }
    if(num%2==1)
        t++;
    for(int i=t;i<num;i++)
    {
        if(s2[i]!=s[i])
            ans2++;
    }
    cout<<min(ans1,ans2);
    /*string s2=s;
    s2.reverse();
    for(long long i=0;i<t;i++)
    {
        if(s2[i]!=s[i])
            ans1++;
    }
    if(num%2==0)
    {
        t++;
    }
    for(int i=t-1;i<num;i++)
    {
        if(s2[i]!=s[i])
        {
            ans2++;
        }
    }
    cout<<min(ans1,ans2);*/
    return 0;
}
