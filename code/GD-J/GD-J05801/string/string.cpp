#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long b=0,ans=0,n=0;
    char c;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b>>c;
        for(int j=0;j<b;j++)
        {
            a.push_back(c);
        }
    }
    int left=0,right=a.size()-1;
    while(left<right)
    {
        if(a[left]!=a[right])
        {
            ans++;
        }
        left++;
        right--;
    }
    cout<<ans;
    return 0;
}
