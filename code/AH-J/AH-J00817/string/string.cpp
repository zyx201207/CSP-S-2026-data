#include<bits/stdc++.h>
using namespace std;
struct{
    long long x;
    char y;
}a[200005];
int main(){
    freopen("string","r",stdin);
    freopen("string","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int q=1,p=n;
    int o=n/2;
    for(int i=1;i<=o;i++){
        long long w=min(a[q].x,a[p].x);
        if(a[q].y==a[p].y){
            a[q].x=a[q].x-w;
            a[p].x=a[p].x-w;
        }else{
            a[q].x=a[q].x-w;
            a[p].x=a[p].x-w;
             ans+=w;
        }
        if(a[q].x>0){
            q--;
            o++;
        }
        if(a[p].x>0){
            p++;
            o++;
        }
        q++;p--;
    }
    cout<<ans;
    return 0;
}
