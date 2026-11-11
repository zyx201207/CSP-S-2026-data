#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string str="";
    while(n--)
    {
        int x;
        string y;
        cin>>x>>y;
        for(int i=1;i<=x;i++) str+=y;
    }
    string str1=str;
    reverse(str.begin(),str.end());
    long long ans=0;
    for(int i=0;i<int(str.size()/2);i++)
        if(str[i]!=str1[i]) ans++;
    cout<<ans<<endl;
    return 0;
}