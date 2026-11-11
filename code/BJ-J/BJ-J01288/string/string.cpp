#include <bits/stdc++.h>
using namespace std;
unsigned long long ans=0,n,sum=0,q[200001];
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        long long x;
        char c;
        cin >> x >> c;
        q[i]=x;
        s=s+c;
    }
    long long l=0,r=s.size()-1;
    while (l<r)
    {
        if (l>r)
        {
            break;
        }
        if (s[l]!=s[r])
        {
            if (q[l]>q[r])
            {

                ans+=q[r];
                q[l]-=q[r];
                q[r]=0;
                r--;
            }
            else if (q[r]>q[l])
            {
                ans+=q[l];
                q[r]-=q[l];
                q[l]=0;
                l++;
            }
            else
            {
                ans+=q[l];
                q[r]=q[l]=0;
                l++;
                r--;
            }
        }
        else
        {
            if (q[l]>q[r])
            {
                q[l]-=q[r];
                q[r]=0;
                r--;
            }
            else if (q[r]>q[l])
            {
                q[r]-=q[l];
                q[l]=0;
                l++;
            }
            else
            {
                q[r]=q[l]=0;
                l++;
                r--;
            }
        }

    }
    cout << ans;
}