#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a[n+2];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int max[m+1],maxn;
    for(int i=1;i<=m;i++) max[i]=-1;

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[i]>max[j]){
                max[j]=a[i];
                maxn=i;
            }
        }
        a[maxn]=-1;
    }

    int ans=max[1];
    for(int i=2;i<=m;i++){
        ans&=max[i];
    }
    cout<<ans;
    return 0;
}
