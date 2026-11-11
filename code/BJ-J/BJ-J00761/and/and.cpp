#include <bits/stdc++.h>
using namespace std;
int n,m,x,maxx=-1;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++)  cin >> a[i];
    if (m==1){
        int ans=a[1];
        for (int i=1;i<=n;i++){
            if (a[i]>ans)
                ans=a[i];
        }
        cout << ans;
    }
    else if (m==2){
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (a[i]&a[j]>maxx)
                    maxx=a[i]&a[j];
            }
        }
        cout << maxx;
    }
    else if (m==n){
        int cnt=a[1];
        for (int i=2;i<=n;i++){
            cnt&=a[i];
        }
        cout << cnt;
    }
    else if (m==3){
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++)
                    x=a[i]&a[j]&a[k];
                    if (x>maxx){
                        maxx=x;
                    }
            }
        }
        cout << maxx;
    }
    else{
        cout << 1;
    }
    return 0;
}
