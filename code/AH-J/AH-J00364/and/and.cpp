#include<bits/stdc++.h>
using namespace std;
int n,a[200005],maxn=-0x3f3f3f3f,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int k=(a[i]&a[j]);
                maxn=max(maxn,k);
            }
        }cout<<maxn;
    }else{
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }cout<<maxn;
    }fclose(stdin);
    fclose(stdout);
    return 0;
}

