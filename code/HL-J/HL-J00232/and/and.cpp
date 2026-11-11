#include<bits/stdc++.h>
using namespace std;
int lg2(int n){
    int m=n,cnt=0;
    while(m){
        m/=2;
        cnt++;
    }
    return cnt-1;
}
bool cmp(int x,int y){
    return x>y;
}
int q(int x,int y){
    return x&y;
}
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    int m,n,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int max_=-9999;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            max_=max(max_,q(a[i],a[j]));
        }
    }
    cout<<max_;
    return 0;
}
