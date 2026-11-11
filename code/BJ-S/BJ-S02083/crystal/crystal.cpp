#include<bits/stdc++.h>
using namespace std;

int n,ans,maxans,num=-1;
long long m,cost,a[500015];

int mx(int a,int b){
    if(a>b) return a;
    if(a<=b) return b;
}

int check(int i){
    while(a[i]==a[i-1]){
        i--;
        if(i==0) return -1;
    }
    return i;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=n-1;i>=maxans-1;i=check(i)-1){
        cost=0;
        for(int j=i;j>=0;j--){
            cost+=a[i]-a[j-1];
            if(cost>m){
                ans=i-j+1;
                break;
            }
        }
        maxans=mx(maxans,ans);
    }
    printf("%d\n",maxans);

    return 0;
}