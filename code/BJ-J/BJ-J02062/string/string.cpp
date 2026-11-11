#include<bits/stdc++.h>
using namespace std;
long long n;
struct Node{
    long long cnt;
    char c;
}arr[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen("string.in","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].cnt>>arr[i].c;
    }
    bool f=true;
    for(int i=1;i<=n/2;i++)
    {
        if(arr[i].c!=arr[i+n-1].c||arr[i].cnt!=arr[i+n-1].cnt)
        {
            f=false;
            break;
        }
    }
    if(f==true)
    {
        cout<<"0";
        return 0;
    }
    long long ans=0;
    long long l=1,r=n;
    while(l<r)
    {
        if(arr[l].cnt==arr[r].cnt)
        {
            arr[r].cnt=arr[l].cnt;
            //if(arr[l].c==arr[r].c)
            //{
                //arr[l].cnt=0;
            //}
            ans=arr[l].cnt;
            l++;
        }
        else
        {
            arr[l].cnt=arr[r].cnt;
            //if(arr[l].c=arr[r].c)
            //{
                //arr[r].cnt=0;
            //}
            ans=arr[r].cnt;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
