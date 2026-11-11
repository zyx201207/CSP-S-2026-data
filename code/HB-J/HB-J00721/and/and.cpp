#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,cnt,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        cnt=a[1]&a[2];
        for(int i=3;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }
    else if(m==2){
        int maxn=INT_MIN;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }
    else{
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
    }
    return 0;
}
