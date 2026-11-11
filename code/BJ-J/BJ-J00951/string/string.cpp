#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,a[200005],no=0,f=0;
    char c[200005];
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    long long l=1,lx=a[1],r=n,rx=a[n];
    while(!((l==r&&(lx==0||rx==0))||l>r))
    {
        if(c[l]!=c[r])
        {
            if(lx>rx)
            {
                no+=rx;
                lx-=rx;
                r--;
                rx=a[r];
            }
            else if(lx<rx)
            {
                no+=lx;
                rx-=lx;
                l++;
                lx=a[l];
            }
            else
            {
                no+=lx;
                l++;
                lx=a[l];
                r--;
                rx=a[r];
            }
        }
        else
        {
            if(lx>rx)
            {
                lx-=rx;
                r--;
                rx=a[r];
            }
            else if(lx<rx)
            {
                rx-=lx;
                l++;
                lx=a[l];
            }
            else
            {
                l++;
                lx=a[l];
                r--;
                rx=a[r];
            }
        }
    }
    cout<<no;
    return 0;
}
