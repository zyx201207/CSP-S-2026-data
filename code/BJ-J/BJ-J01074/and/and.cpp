#include <bits/stdc++.h>
using namespace std;
int n,m;
int res_max;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
     cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<res_max||a[j]<res_max)continue;
            else{
                int x=a[i]&a[j];
                res_max=max(res_max,x);
            }
        }
    }
    cout<<res_max;
    return 0;
}

