#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l= 1,r;
char b[200005];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i = 1; i<= n; i++)
    {

        cin>>a[i]>>b[i];

    }
    r = n;
    while(l<r)
    {
        if(b[l] == b[r])
        {
            if(a[l] > a[r])
            {

                a[l] -= a[r];
                r--;
            }
            else if(a[l] == a[r]){
                l++;
                r--;
            }
            else
            {

                a[r] -= a[l];
                l++;
            }
        }
        else{
            if(a[l] > a[r])
            {
                ans+=a[r];
                a[l] -= a[r];
                r--;
            }
            else if(a[l] == a[r])
            {
                ans+=a[l];
                l++;
                r--;
            }
            else
            {
                ans+= a[l];
                a[r] -= a[l];
                l++;
            }

        }
    }
    cout<<ans;
    return 0;
    //
}
