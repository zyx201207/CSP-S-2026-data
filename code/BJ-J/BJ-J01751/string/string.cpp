#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }

    int a1=0;
    int l=0,r=s.size()-1;
    while(l<=r)
    {
        if(s[l]!=s[r])
        {
            a1++;
        }
        l++;
        r--;
    }
    cout<<a1;
}
