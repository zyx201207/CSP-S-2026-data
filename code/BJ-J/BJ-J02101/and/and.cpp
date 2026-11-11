#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool b[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long l=0;
    for(long long i=(1<<30);i!=0;i=(i>>1)){
            int sum=0;
        for(int j=1;j<=n;j++){
            if((a[j]&i)!=0){
                sum++;
            }
        }
        if(sum>=m){
            l=i;
            break;
        }
    }
    long long ans=0;
    for(long long i=l;i!=0;i=(i>>1)){
            int sm=0;
        for(int j=1;j<=n;j++){
            if(b[j]==1)continue;
            if((a[j]&i)!=0)sm++;
        }
        if(sm>=m){
            ans+=i;
            for(int j=1;j<=n;j++){
                if(b[j]==1)continue;
                if((a[j]&i)==0)b[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
