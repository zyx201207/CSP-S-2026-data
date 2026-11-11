#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxn=-1,n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(maxn<a[i]&a[j]) maxn=a[i]&a[j];
            }
        }
    }
    cout<<maxn;
    return 0;
}
