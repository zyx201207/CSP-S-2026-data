#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000001];
char ch[10000001];
int n;
long long cnt,ans;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>ch[i];
        cnt+=a[i];
    }
    for(int i=0,j=cnt-1;i!=j;i++,j--)
    {
        int x=0,y=n-1;
        if(i==a[x])
        {
            x++;
        }
        if(i==a[y])
        {
            y--;
        }
        if(ch[x]!=ch[y]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
