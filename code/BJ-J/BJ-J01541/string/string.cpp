#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    while(n--)
    {
        int s1;
        char a;
        cin>>s1>>a;
        sum+=s1;
        for (int j=0;j<s1;j++)
        {
            s+=a;
        }
    }
    int l=0,r=sum-1;
    int num=0;
    while (l<r)
    {
        if (s[l]!=s[r])
        {
            num++;
        }
        l++;
        r--;
    }
    cout<<num;
    return 0;
}
