#include<bits/stdc++.h>
using namespace std;
int n;
struct hui
{
    int liang;
    char zi;
};
hui a[2005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].liang>>a[i].zi;

    }
    if(n<=1)
    {
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=a[i].liang;
    }
        //cout<<cnt<<endl;
    string z;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].liang;j++)
        {
            z+=a[i].zi;
        }
    }
    //cout<<z<<endl;
    int ans=0;
    int l=0;
    int r=cnt-1;
    for(int i=1;i<=cnt/2;i++)
    {
        if(z[l]==z[r])
        {
            ans+=0;
        }
        else{
            ans++;
        }
        l++;
        r--;
        if(l>=r)
        {

            break;
        }
    }
cout<<ans<<endl;
//for(int i=1;i<=n;i++)
//{

    //cout<<a[i].liang<<a[i].zi;
//}

    return  0;
}
