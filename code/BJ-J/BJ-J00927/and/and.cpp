#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cur[200010],num,ax[40],ans,xnum=30;
bool bit(int b,int c){
    for(int i=1;i<c;i++) b/=2;
    return b%2;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    num=n;
    while(xnum>0){
        int flag=0;
        for(int i=1;i<=xnum;i++) ax[i]=0;
        for(int i=1;i<=num;i++){
            int cpy=a[i],x=1;
            while(cpy){
                if(cpy%2) ax[x]++;
                x++;
                cpy/=2;
            }
        }
        for(int j=xnum;j>=1;j--){
            if(ax[j]>=m){
                int num2=0;
                flag=1;
                xnum=j-1;
                ans+=pow(2,j-1);
                for(int i=1;i<=num;i++){
                    if(bit(a[i],j)) cur[++num2]=a[i];
                }
                num=num2;
                break;
            }
        }
        for(int i=1;i<=num;i++) a[i]=cur[i];
        if(flag==0) xnum=0;
    }
    cout<<ans;
    return 0;
}
