#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[200005];
char brr[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i]>>brr[i];
    for(int i=1,j=n;i<j;)
    {
        if(brr[i]==brr[j])
        {
            if(arr[i]<arr[j])
            {
                arr[j]-=arr[i];
                i++;
            }
            else if(arr[i]>arr[j])
            {
                arr[i]-=arr[j];
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if(arr[i]<arr[j])
            {
                arr[j]-=arr[i];
                ans+=arr[i];
                i++;
            }
            else if(arr[i]>arr[j])
            {
                arr[i]-=arr[j];
                ans+=arr[j];
                j--;
            }
            else
            {
                ans+=arr[i];
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
