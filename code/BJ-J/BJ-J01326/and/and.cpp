#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,a[N],x,y,maxn=0;
bool flag;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        x=a[i];
        flag=1;
        for(int j=i;j<=m+i-1;j++){
            x=(x&a[j]);
            if(maxn>x){
                flag=0;
                break;
            }
        }
        if(flag) maxn=max(maxn,x);
    }
    cout<<maxn;
    return 0;
}
