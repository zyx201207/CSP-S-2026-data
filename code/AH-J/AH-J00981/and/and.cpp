#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num;
int sum;
int flag(int x,int y){
    if(x&y==0){
        return 0;
    }
    return 1;
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    long long a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n && sum<m;i++){
        if(flag(a[i],a[i+1])){
            sum++;
            num=a[i];
        }
    }
    printf("%lld",num);

    return 0;
}
