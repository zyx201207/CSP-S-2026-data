#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ai;
        char ci;
        cin>>ai>>ci;
        while(ai--)
            s+=ci;
    }
    long long len=s.size()/2-1;
    for(int i=0;i<=len;i++)
    {
        int j=s.size()-i-1;
        if(s[i]!=s[j])
            sum++;
    }
    cout<<sum;
    return 0;
}