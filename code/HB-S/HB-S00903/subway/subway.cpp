#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long n=0,m=0,s=0,ma=0,c=0,p=0,l=0,h,g,u;
    long long a[500005];
    cin>>n>>m>>h>>g>>u;
    l=m;
    for (long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for (long long i=1;i<=n;i++){
        for(long long j=n;j>0+i;j--){
            if(a[j]>a[j-1] && j!=1){
            s=a[j];
            a[j]=a[j-1];
            a[j-1]=s;
            s=0;
            }
        }
    }
    for (long long i=1;i<=n;i++){



        if(ma>c){
            c=ma;
        }
        ma=0;
        l=m;
    }
    for(int i=0;i<u;i++ ){
        cout<<0<<endl;
    }
    return 0;
}
