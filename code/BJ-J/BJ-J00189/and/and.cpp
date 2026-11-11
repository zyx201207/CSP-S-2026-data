#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-1,ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    for(int i=1;i<=150;i++){
        ans=a[i];
        for(int j=i+1;j<=m+i-1;j++){
            ans=ans&a[j];
        }
        if(ans>maxn) maxn=ans;
    }
    cout<<maxn;
    return 0;
}
