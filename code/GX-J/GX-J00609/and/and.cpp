#include <bits/stdc++.h>
using namespace std;

int num,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int a[200005];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=num){
            ans=num;
            num=a[i];
        }
        if(a[i]>ans&&a[i]<num){
            ans=a[i];
        }
    }
    cout << ans;
    return 0;
}
