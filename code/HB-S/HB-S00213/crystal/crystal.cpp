#include<bits/stdc++.h>
using namespace std;
const int MX=5e5+5;
long long n,m;
long long ans=LONG_MIN;
bool f=0;
bool f2=0;
long long fnn;
long long cnt=0;
long long a[MX];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int k=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            f=1;
        }
    }
    fnn=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(fnn!=a[i]-a[i-1]){
            f2=1;
            break;
        }
    }
    if(f2==0){
        for(int i=0;i<=n;i++){
            if(k-i*fnn>=0){
                k-=i*fnn;
                cnt++;
            }
            else{
                break;
            }
        }
        cout<<min(n,cnt);
        return 0;
    }
    if(f==0){
        for(int i=0;i<=n;i++){
            if(k-i>=0){
                k-=i;
                cnt++;
            }
            else{
                break;
            }
        }
        cout<<min(n,cnt);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int k=m;
        for(int j=1;j<=i;j++){
            if(k<0){
                break;
            }
            k=k-(a[i]-a[j]);
            ans=max((long long)j,ans);
        }

    }
    cout<<ans;
    return 0;
}
