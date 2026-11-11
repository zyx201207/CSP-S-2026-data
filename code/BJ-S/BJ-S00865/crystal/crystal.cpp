#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt=0;
    int a[100005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int p=max(a[1],a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]+j==p)
            {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt+1;
    return 0;
}
