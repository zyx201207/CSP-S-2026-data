///GZ-J00105 陈艺文
#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxx=0,i1;cin >>n >>m;
    for(long long i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]>maxx){
            maxx=a[i];
            i1=i;
        }
    }
    a[i1]=0;
    long long maxx2=0;
    for(long long i=2;i<=m;i++){
        for(long long j=1;j<=n;j++){
            long long x=maxx&a[j];
            if(maxx2<x){
                maxx2=x;
                i1=j;
            }
        }
        maxx=maxx2;
        maxx2=0;
        a[i1]=0;
    }
    cout <<maxx;
    return 0;
}
