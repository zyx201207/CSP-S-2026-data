#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],mx=0,sum=0,sun;
void ad(long long x,long long y){
    if(y==1) sun=0;
    for(int i=x;i<=n;i++){
        sum=sun;
        if(sum!=0) sum=(sum&a[i]);
        else sum=a[i];
        if(y<m){
            sun=sum;
            ad(i+1,y+1);
        }else{
            mx=max(mx,sum);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    ad(1,1);
    cout<<mx;
    return 0;
}
