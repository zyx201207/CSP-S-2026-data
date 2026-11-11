#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<string >s(n);
    vector<int >num(n);

    int tot=0;
    for(int i=0;i<n;i++)
    {

        cin>>num[i]>>s[i];
        tot+=num[i];
    }
    long long c=0;
    vector<string >sa(n*tot);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<num[i];j++)
        {
            sa[c]=s[i];
            c++;
        }
    }
    int cnt=0;
    for(int i=0;i<n*tot/2;i++)
    {
        if(sa[i]!=sa[n-1-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    /*
    int b=0;
    int f=0;
    int cnt=0;
    int cur=0;
    string curs=s[0];
    for(int i=0;i<n/2&&b==1;i++)
    {

        if(num[i]>num[n-i]+cur)
        {

            if(s[i]==curs)
            {
                num[i]-=cur;
            }
            else
            {
                num[i]-=cur;cnt+=cur;
            }
            if(s[i]==s[n-i-1])
            {
                num[i]-=num[n-i-1];
            }
            else
            {
                num[i]-=num[n-i-1];cnt+=num[n-i-1];
            }
            cur-=num[i];
        }
        else if(num[i]==num[n-i]+cur)
        {
            if(s[i]==curs)
            {
                num[i]-=cur;
            }
            else
            {
                num[i]-=cur;cnt+=cur;
            }
            if(s[i]==s[n-i-1])
            {
                num[i]-=num[n-i-1];
            }
            else
            {
                num[i]-=num[n-i-1];cnt+=num[n-i-1];
            }
            cur-=num[i];

        }
        else
        {

        }

    }*/
    return 0;
}
