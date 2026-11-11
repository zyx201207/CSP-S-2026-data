#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(int i=0;i<n;i++)
    {
        int t;
        char c;
        cin>>t>>c;
        for(int i=0;i<t;i++)
        {
            s+=c;
        }
    }
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j]) ans++;
        i++;
        j--;
    }
    cout<<ans;
    return 0;
}
