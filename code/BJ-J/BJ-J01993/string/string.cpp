#include<bits/stdc++.h>
using namespace std;
string s={};
struct node
{
    int num;
    char c;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    node a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        cin>>a[i].c;
        for(int j=1;j<=a[i].num;j++)
        {
            s+=a[i].c;
        }
    }
    int len=s.size();
    int l=0,r=len-1;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
}
