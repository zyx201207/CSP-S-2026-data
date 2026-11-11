#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct Str
{
    int a;
    char ch;
}str[1000001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i].a>>str[i].ch;
    }
    int l=1,r=n;
    while(l<r)
    {
        bool flag=(str[l].ch==str[r].ch);
        if(str[l].a>str[r].a)
        {
            if(flag==false)
            {
                ans+=str[r].a;
            }
            str[l].a-=str[r].a;
            str[r].a=0;
            r--;
        }
        else if(str[l].a<str[r].a)
        {
            if(flag==false)
            {
                ans+=str[l].a;
            }
            str[r].a-=str[l].a;
            str[l].a=0;
            l++;
        }
        else
        {
            if(flag==false)
            {
                ans+=str[r].a;
            }
            str[l].a=0;
            str[r].a=0;
            l++;
            r--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    cout<<ans;
    return 0;
}