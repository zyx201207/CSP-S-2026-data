#include<bits/stdc++.h>
using namespace std;
int a[5000005];
long long n,m;
bool flag=false;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long u;
    cin>>a[1];
    u=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]!=u)flag=true;
    }
    if(flag){
        long long k=a[2]-a[1];
        long long cnt=0;
        long long l=1;
        for(long long i=1;i<=n/2;i++){
            cnt=cnt+i*k;
            if(cnt==m){
                l++;
                cout<<l;
                return 0;
            }
            else if(cnt>=m&&l!=1){
                cout<<l-1;
                return 0;
            }
            else if(cnt>=m&&l==1){
                cout<<l;
                return 0;
            }
            else l++;
            }
            m-=cnt;
            for(long long i=n/2+1;i<=n-1;i++){
                m-=k*i;
            if(m>=0){
                l++;
            }
            else if(m==0){
                l++;
                cout<<l;
                return 0;
            }else{
                cout<<l;
                return 0;
            }
        }
        cout<<l;
    }else{
        cout<<n;
    }
return 0;
}
