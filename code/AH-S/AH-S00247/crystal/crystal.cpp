#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,c[500005],cnt=1,maxn,f=1,r;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    r=b;
    for(int n=1;n<=a;n++){
        cin>>c[n];
    }
    sort(c+1,c+a+1);
    for(int n=3;n<=a;n++){
        if(c[n]-c[n-1]!=c[n-2]-c[n-1]){
            f=0;
        }
    }
    for(int m=1;m<=a;m++){
        long long cnt=0;
        b=r;
        if(f&&m>1) break;
        if(c[m]==c[m-1]) continue;
        for(long long n=m;n<=a;n++){
            if((c[n]-c[n-1])*(n-m)>b){
                maxn=max(maxn,n-m-1);
                break;
            }
            else{
                b-=(c[n]-c[n-1])*(n-m);
            }
        }
    }
    cout<<maxn;
    return 0;
}
