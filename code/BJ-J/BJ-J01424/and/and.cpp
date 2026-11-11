#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[2000005];
bool s[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=29;i>=0;i--){
        long long x=(1<<i),num=0;
        for(int j=1;j<=n;j++){
        if(!s[j]){
            num+=((a[j]&x)>0);
        }}
        if(num>=m){
            ans|=x;
            for(int j=1;j<=n;j++)
                if(!s[j]){
                    if((a[j]&x)==0){
                        s[j]=1;
                    }
                }

        }

    }cout<<ans;
    return 0;
}

