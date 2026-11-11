#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],f[2001][2001],s=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(n>2000&&s<=1024){
        int cnt=0,ans=0;
        for(int i=1;i<=s;i++){
            for(int j=1;j<=n;j++){
                int k=a[j]&i;
                if(k==i)cnt++;
            }
            if(cnt>=m)ans=i;
            cnt=0;
        }
        cout<<ans<<endl;
        return 0;
    }else if(n>2000){
        sort(a+1,a+n+1);
        cout<<a[n+1-m]<<endl;
        return 0;
    }
    int c=-1;
    for(int i=1;i<=n;i++){
        c=max(c,a[i]);
        f[i][1]=c;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}
