#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll M=1e8+5;
ll n[M],m[M];
ll f(ll x,ll s){
    int sums=-1;
    for(ll i=0;i<s;i++){
        if(sums>=(x-m[i])){
            sums=(x-m[i]);
        }
    }
    return sums;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a,b,bs,sum,msum=-1,cnt,is;
    cin>>a>>b;
    for(ll i=0;i<a;i++){
        cin>>n[i];
    }
    sort(n,n+a);
    for(ll i=1;i<a;i++){
        bs=b;
        cnt=0;
        sum=0;
        for(int j=0;j<a;j++){
            m[j]=0;
        }
        for(int j=0;j<a;j++){
            if(m[j]!=n[i]){
                m[cnt++]=n[j];
            }
        }
        is=i;
        while(1){
            bs-=f(n[is],is);
            if(bs<0){
                break;
            }
            sum++;
            for(int j=0;j<a-1;j++){
                if(m[j]==f(n[i],is)){
                    m[j]=f(n[i],is);
                    break;
                }
            }
        }
        if(msum<sum){
            msum=sum;
        }
    }
    cout<<msum;
    return 0;
}
