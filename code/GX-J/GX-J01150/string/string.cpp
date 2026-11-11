#include<bits/stdc++.h>
#define ll long long
struct str
{
    int a;
    char c;
};
str x[110000],y[110000];
using namespace std;
int n,a,b=110000;
char c[1000000];
ll sum,cnt,m[1000000],half;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i]>>c[i];
        sum+=m[i];
    }
    half=sum/2;
    for(int i=1;half>0;i++)
    {
        x[i].a=m[i],x[i].c=c[i];
        half-=m[i];
        a=max(a,i);
    }
    half=sum/2;
    for(int i=n;half>0;i--)
    {
        y[i].a=m[i],y[i].c=c[i];
        half-=m[i];
        b=min(b,i);
    }
    for(int i=1;i<=a;)
    {
        for(int j=n;j>=b;)
        {
            if(x[i].c!=y[j].c)
                cnt+=min(x[i].a,y[j].a);
            if(x[i].a>y[j].a)
                x[i].a-y[j--].a;
            else if(x[i].a<y[j].a)
                y[j].a-x[i++].a;
            else
                i++,j--;
            break;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
