#include <bits/stdc++.h>
using namespace std;

long long a[100010],ans=0,n;
char b[100010];

long long f(long long i,long long x,long long y){
        if(b[i]==b[n-i+1]){
            return 0;
        }
        if(x==y){
            ans+=x;
            return 0;
        }
        ans+=min(x,y);
        if(x>y){
            x-=y;
            f(i-1,x,a[n-i-1]);
            a[n-i-1]=0;
            return 0;
        }else{
            y-=x;
            f(i+1,y,a[i+1]);
            a[i+1]=0;
            return 0;
        }
}


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int j=1;j<=n;j++){
        cin>>a[j]>>b[j];
    }
    for(int i=1;i<=n;i++){
        f(i,a[i],a[n-i]);
        a[i]=0;
        a[n-i]=0;
    }
    cout<<ans;
return 0;
}
