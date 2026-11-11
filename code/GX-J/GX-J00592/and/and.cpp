#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m,cnt=0,cut=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[1];
    }
    if(n==m){
        sort(a+1,a+n+1);
        while(a[1]>0){
            a[1]/=2;
            cnt++;
        }
        for(int i=1;i<=cnt;i++){
            cut*=2;
        }
        cout<<cut-1;
    }
    return 0;
}
