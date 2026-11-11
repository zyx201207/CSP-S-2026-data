#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
     return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0,d=0,gs=1,ym=0;
    cin>>n>>m;
    ym=m;
   long long a[n]={0};
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);

        for( long long i=0;i<n;i++){
        m=ym,gs=1;
        for(long long j=i+1;j<n;j++){
            if(m-(a[i]-a[j])>=0){
                m=m-(a[i]-a[j]);
                gs++;
        if(gs>d){
            d=gs;
        }
        }
    }
        }
    cout<<d;
return 0;
}
