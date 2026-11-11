#include<iostream>
using namespace std;
const long long MX=2e5+10;
string pt="";
long long n,ans;
struct node
{
    long long a;
    char c;
}de[MX];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>de[i].a>>de[i].c;
    }
    long long l=1,r=n;
    while(l<r)
    {
        if(de[l].a>de[r].a)
        {
            if(de[l].c==de[r].c)
            {
                de[l+1].a+=de[l].a-de[r].a;
                ans+=de[l].a-de[r].a;
                de[l].a-=de[r].a;
            }
            else
            {
                de[l+1].a+=de[l].a-de[r].a;
                ans+=de[l].a;
            }
            l++;
            r--;
        }
        else if(de[l].a<de[r].a)
        {
            if(de[l].c==de[r].c)
            {
                de[r-1].a+=de[r].a-de[l].a;
                ans+=de[r].a-de[l].a;
                de[r].a-=de[l].a;
            }
            else
            {
                de[r-1].a+=de[r].a-de[l].a;
                ans+=de[r].a;
            }
            l++;
            r--;
        }
        else
        {
            if(de[l].c!=de[r].c)
            {
                ans+=de[l].a;
            }
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
