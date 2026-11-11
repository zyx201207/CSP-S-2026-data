#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long tmp=LLONG_MIN;
        for(int i=1;i<=n;i++){
            tmp=max(a[i],tmp);
        }
        cout<<tmp;
        return 0;
    }
    if(m==n){
        long long tmp=a[1];
        for(int i=2;i<=n;i++){
            tmp&=a[i];
        }
        cout<<tmp;
        return 0;
    }
    if(m==(n-1)){
        long long tmp=0;
        for(int i=1;i<=n;i++){
            long long tmp1=1;
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                tmp1&=a[j];
            }
            tmp=max(tmp1,tmp);
        }
        cout<<tmp;
        return 0;
    }
    if(m==2){
        long long tmp=0;
        for(int i=1;i<=n;i++){
            long long tmp1=0;
            for(int j=1;j<=n;j++){
                tmp1=a[i]&a[j];
                tmp=max(tmp1,tmp);
            }
        }
        cout<<tmp;
        return 0;
    }
}