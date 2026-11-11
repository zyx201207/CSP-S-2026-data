#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200000],b[200000],maxx=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        for(int j=1;j<m;j++){
            for(int w=i;w<=n;w++){
                b[i]=b[i]&a[w];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]>maxx){
            maxx=b[i];
        }
    }
    cout<<maxx;
    return 0;
}
