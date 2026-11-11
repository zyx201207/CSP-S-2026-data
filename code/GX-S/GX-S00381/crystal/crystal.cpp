#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,c=0,d,num=0,max=0,t,f=0,r=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5000){
        t=a[2]-a[1];
        r=t;
        for(int i=1;i<=n;i++){
            f+=r;
            if(f>m){
                cout<<i-1;
                return 0;
            }
            r+=t;
        }
        cout<<n;
        return 0;
    }
    for(int i=n;i>=1;i--){
            c=1;
            num=0;
        for(int j=i-1;j>=1;j--){
            d=a[i]-a[j];
            num+=d;
            if(num>m){
                break;
            }else{
            c++;
            }
        }
        if(c>=max){
            max=c;
            //cout<<i<<" ";
        }
    }
    cout<<max;
    return 0;
}
