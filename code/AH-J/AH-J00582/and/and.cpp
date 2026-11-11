#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
    }else if(m==n){
        int k=1;
        for(int i=1;i<=n;i++){
            k=(k&a[i]);
        }
        cout<<k;
    }else if(m==2){
        int maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
    }else{
        cout<<a[m];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
