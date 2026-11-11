#include<bits/stdc++.h>
using namespace std;
const int N=5e6+7;
int arr[N];
int C[N];
int main()
{
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        bool flag=0;
        for(int i=2;i<=n;i++)
        {
            if(arr[i]-arr[i-1]>d)
            {
                flag=0;
                break;
            }
            if(arr[i]-arr[i-1]!=d)
            {
                flag=1;
                break;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+3;j<=n;j++)
            {
                flag=0;
                int k=0;
                for(k=i+3;k<=j;k+=2)
                {
                    if(arr[k]-arr[k-2]>d)
                        flag=1;
                }
                if(flag)
                    continue;
                if(arr[j]-arr[k-2]>d&&k-2!=j)
                    continue;

                for(k=i+2;k<=j;k+=2)
                {
                    if(arr[k]-arr[k-2]>d)
                        flag=1;
                }
                if(flag)
                    continue;
                if(arr[j]-arr[k-2]>d&k-2!=j)
                    continue;
                cnt++;
                //cout<<i<<" "<<j<<'\n';
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
