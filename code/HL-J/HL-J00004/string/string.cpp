#include<bits/stdc++.h>
using namespace std;
int n;
struct fg
{
    long long a;
    string b;
}vbn[200005];

void check()
{
    string s="";
    int wert=0;
    for(int i=1;i<n;i++)
     {
         if(vbn[i].b==vbn[i+1].b) wert=0;
         else wert=1;
     }
     if(!wert)
     {
         cout<<0;
         return;
     }

    long long cnt=1,ans=0;
    for(int i=1;i<n;i++)
    {
        if(vbn[i].a==vbn[i+1].a)
        {
            cnt=1;
        }
        else cnt=0;
    }
    if(cnt)
    {
        for(int i=1;i<n;i++)
        {
            cout<<vbn[i].b<<" "<<vbn[i+1].b<<endl;
            if(vbn[i].b!=vbn[i+1].b)
            {
                ans=cnt;
                cnt=0;
            }
            else
            {
                cnt++;
                cout<<cnt<<" ";
            }
        }
        if(ans>cnt) cout<<ans*vbn[1].a;
        else cout<<cnt*vbn[1].a;
        return;

    }
    int y;
    for(int i=1;i<n;i++)
    {
        y=max(vbn[i].a,vbn[i+1].a);
    }
    cout<<y;

}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>vbn[i].a;
        cin>>vbn[i].b;

    }
    check();

}

