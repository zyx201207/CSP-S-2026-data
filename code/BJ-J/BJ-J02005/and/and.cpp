#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=2147483647,box[10];
bool flag=1;
bool check(int x){
    x++;
    for(int i=1;i<=31;i++){
        if(x==(1<<i))   return 1;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        flag&=check(a[i]);
    }
    sort(a+1,a+n+1);
    if(flag){
        for(int i=n;i>n-m;i--){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }

    if(m==n){
        for(int i=1;i<=n;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(a[n]<4){
        for(int i=1;i<=n;i++){
            box[a[i]]++;
        }
        if(box[3]>=m){
            cout<<3;
            return 0;
        }
        if(box[3]+box[2]>=m){
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    cout<<a[n/2];
    return 0;
}