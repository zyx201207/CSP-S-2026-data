#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>=y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,ans=0;
    long long m;
    cin>>n>>m;
    long long a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(n<=5000){
        long long b[5005];
        for(int i=1;i<n;i++){
            b[i]=a[i]-a[i+1];
        }
        long long s,sum,ansq;
        for(int i=1;i<=n;i++){
            sum=0,s=0,ansq=1;
            for(int j=i;j<n;j++){
                s+=b[j];
                sum+=s;
                if(sum>m){
                    break;
                }
                ansq++;
            }
            if(ans<ansq){
                ans=ansq;
            }
        }
    }else{
        int c;
        for(int i=1;i<=n;i++){
            c=a[1]-a[i];
            if(m-c>=0){
                ans++;
                m-=c;
            }else{
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}
