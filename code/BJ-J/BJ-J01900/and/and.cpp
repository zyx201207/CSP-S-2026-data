#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxn=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    sort(a,a+n);
    int maxx=-1;
    for(int i=n;i>=1;i--){
        for(int j=n-1;j>=1;j--){
            if(i<maxx){
                cout<<maxx;
                return 0;
            }else{
                maxx=max(maxx,a[i]&a[j]);
            }
        }
    }
    cout<<maxx;
    return 0;
}
