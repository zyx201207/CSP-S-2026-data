#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int s1[200005],s2[200005];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,maxx=INT_MIN;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        sort(a,a+n);
        maxx=a[n-1];
    }else if(m==2){
        maxx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
    }else if(m=n-1){
        s[0]=a[0];
        for(int i=0;i<n;i++){
            s1[i]=s1[i-1]&a[i];
        }
        s2[n-1]=a[n-1];
        for(int i=n-2;i>=0;i++){
            s2[i]=a[i]&s[i+1];
        }
        maxx=s2[1];
    `   for(int i=0;i<=n;i++){
            maxx=max(s1[i]&s2[2],maxx);
        }
    }
    cout<<maxx;
    return 0;
}
