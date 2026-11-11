#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005],maxn=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int x=0,y=0x3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=max(a[i],x);
        y=y&a[i];
    }
    if(m==1){
        cout<<x;
        return 0;
    }
    if(m==n){
        cout<<y;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(a[i]&a[j],maxn);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            int b=0x3f;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                else b=b&a[j];
            }
            maxn=max(b,maxn);
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}
