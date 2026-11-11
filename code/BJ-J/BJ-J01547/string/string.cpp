#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        string a;
        cin>>num>>a;
        for(int j=i;j<i+num;j++)
        {
            s+=a;
        }
    }
    int half=s.size()/2;
    string sl[half],sr[half];
    for(int i=0;i<half;i++)
    {
        sl[i]=s[i];
    }
    int cnt=0;
    int mo;
    if(s.size()%2==0)
    {
        mo=half+1;
    }
    else{
        mo=half+2;
    }
    int ans=0;
    for(int i=0;i<half;i++)
    {
        if(sl[i]==sr[i])
        {
        }
        else{
            ans++;
        }
    }
    cout<<ans;
    return 0;
}