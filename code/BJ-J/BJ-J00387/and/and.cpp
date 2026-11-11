#include<bits/stdc++.h>
using namespace std;
long n,m;
long a[200002];
long ans=0;
long xuan[200002];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long i=0;i<n;i++){
        cin>>a[i];
    }
    long o=-1;
    for(long i=1;i<m;i++) xuan[i]=1;
    while(xuan[n]!=1){
        xuan[0]++;
        long cnt=0;
        long ans=-1;
        for(long i=0;i<=n;i++){
            if(xuan[i]==2){
                xuan[i]=0;
                xuan[i+1]++;
            }
            if(xuan[i]==1){
                cnt++;
                if(ans==-1){
                    ans=a[i];
                }else{
                    ans&=a[i];
                }
            }
        }
        if(cnt==m){
            o=max(o,ans);
        }
    }
    cout<<o;
    return 0;

}
