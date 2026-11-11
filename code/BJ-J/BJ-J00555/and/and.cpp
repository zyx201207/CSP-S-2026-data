#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=-1;
    if (m==1){
        for (int i=1;i<=n;i++){
            ans=max(a[i],ans);
        }
    }
    else if (m==2){
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }
    else if (m==n){
        ans=a[1];
        for (int i=2;i<=n;i++){
            ans=ans&a[i];
        }
    }
    else if (m==n-1){
        for (int i=1;i<=n;i++){
            long long cnt;
            for (int j=1;j<=n;j++){
                if (j==i)continue;
                if (j==1 || (j==2 && j==i+1))cnt=a[j];
                else {
                    cnt&=a[j];
                }
            }
            ans=max(ans,cnt);
        }
    }
    else if (m==n-2){
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                long long cnt;
                for (int k=1;k<=n;k++){
                    if (k==i || k==j)continue;
                    if (k==1 || (k==2 && k==i+1) || (k==3 && k==j+1 && k==i+2))cnt=a[k];
                    else {
                        cnt&=a[k];
                    }
                }
                ans=max(ans,cnt);
            }
        }
    }
    else if (m==n-3){
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                for (int k=j+1;k<=n;k++){
                    long long cnt;
                    for (int l=1;l<=n;l++){
                        if (l==i || l==j || l==k){
                            continue;
                        }
                        if (l==1 || (l==2 && l==i+1) || (l==3 && l==j+1 && l==i+2) || (l==4 && l==k+1 && l==j+2 && l==i+3))cnt=a[l];
                        else {
                            cnt&=a[l];
                        }
                    }
                    ans=max(ans,cnt);
                }
            }
        }
    }
    else {
        ans=a[1];
        for (int i=2;i<=m;i++){
            ans&=a[i];
        }
    }
    cout<<ans;
    return 0;
}
