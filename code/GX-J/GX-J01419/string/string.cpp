#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int str_num;
    string enter_str;
    string s;
    int sum=0;

    for(int i=1;i<=n;i++)
    {
        cin>>str_num;
        sum+=str_num;
        cin>>enter_str;
        for(int j=1;j<=str_num;j++)
        {
            s+=enter_str;
        }
    }

    char std_str=s[0];
    int cnt=sum;
    for(int i=0;i<=sum;i++)
    {
        if(s[i]==std_str&&cnt>0)
        {
            cnt--;
            std_str==s[i];
        }
    }
    if(cnt==0) cout<<cnt;
    else
    {

    }
    string s1=s;
    int mid=0;
    mid=sum/2-1;
    for(int i=0;i<=mid;i++)
    {
        s1[sum-i]=s1[i];
    }
    int cnt_c=0;
    for(int i=1;i<=sum;i++)
    {
        if(s1[i]!=s[i]) cnt_c++;
    }
    cout<<cnt_c;
    return 0;
}
