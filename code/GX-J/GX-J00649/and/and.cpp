#include<bits/stdc++.h>
using namespace std;
int n,m,maxn=-114514;
int a[1000100];
int an;
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n-i;j++){
            an=a[j];
            for(int c=j+1;c<=j+m;c++){
                an=an&a[c];
            }
            maxn=max(maxn,an);
        }
    }
    cout<<maxn;
    return 0;
}

