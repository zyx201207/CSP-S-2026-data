#include <bits/stdc++.h>
using namespace std;

int _and(int a,int b){
    return a&b;
}

bool cmp(int a,int b){
    return a>b;
}

const int MAXN=2e5+5;
int a[MAXN];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n==m){
        cin >> a[1];
        int ans=a[1];
        for(int i=2;i<=n;i++){
            cin >> a[i];
            ans=_and(ans,a[i]);
        }
        cout << ans;
    } else if(m==1){
        int maxi=-1;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            if(a[i]>maxi) maxi=a[i];
        }
        cout << maxi;
    } else if(m==2){
        for(int i=1;i<=n;i++) cin >> a[i];
        int maxn=-1;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int res=_and(a[i],a[j]);
                if(res>maxn) maxn=res;
            }
        }
        cout << maxn;
    } else{
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a+1,a+n+1,cmp);
        int ans=a[1];
        for(int i=2;i<=m;i++) ans=_and(ans,a[i]);
        cout << ans;
    }
    return 0;
}
