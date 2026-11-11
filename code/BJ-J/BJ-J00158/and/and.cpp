#include<iostream>
#include<cstring>
using namespace std;
const int N=3000000;
long long n,m,a[N];
long long low(long long k){
    long long f=1;
for(int i=1;i<=k;i++){
    f*=2;
}
    return f;
}
bool bax(long long k){
    long long j=0;
    for(int i=1;i<=n;i++){
        j+=k%2;
        k=k/2;
    }
    if(j==m)
        return true;
    return false;
}
long long fin(long long k){
    long long h=0;
    bool vist=true;
    for(int i=1;i<=n;i++){
        if(vist&&k%2==1){
            h=a[i];
            vist=false;
        }
        if(!vist&&k%2==1)
        h&=a[i];
        k=k/2;
    }
    return h;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long maxx=0,c=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            c=a[i];
        }
        c&=a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx<<endl;
        return 0;
    }
    if(m==n){
        cout<<c;
        return 0;
    }
    if(m==2){
            long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    cout<<ans<<endl;
    return 0;
    }
    if(n<=20){
            long long minn=0;
        for(int i=1;i<=low(n);i++){
            if(bax(i)){
                minn=max(minn,fin(i));
            }
        }
        cout<<minn<<endl;
        return 0;
    }

    return 0;
}
