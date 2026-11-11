#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct num
{
    int a;
    char b;
}numb[200095];
int main()
{
   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>numb[i].a>>numb[i].b;
    }
    for(int i = 0,j = n-1;i<j;)
    {
        int tc=abs(numb[i].a-numb[j].a);
        int c=min(numb[i].a,numb[j].a);
        if(numb[i].b!=numb[j].b)ans+=c;
        if(numb[i].a>numb[j].a)
        {
            numb[i].a-=c;
            j--;
            continue;
        }
        else if(numb[i].a<numb[j].a)
        {
            numb[j].a-=c;
            i++;
            continue;
        }
        else
        {
            i++;
            j--;
            continue;
        }
    }
    cout<<ans;
    return 0;
}
