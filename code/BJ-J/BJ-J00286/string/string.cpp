#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    int n;
    long long sum=0;
    long long ans=0;
    string s;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        string y;
        cin>>x>>y;
        for(int j = 1;j <= x;j++)
        {
            s+=y;
        }
        sum+=x;
    }
    for(int i = 0;i < (sum+1)/2;i++)
    {
        if(s[i]!=s[sum-1-i])
        {
            s[i]=s[sum-1-i];
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
