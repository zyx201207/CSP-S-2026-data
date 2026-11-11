#include<bits/stdc++.h>
using namespace std;
const long long N=500010;
long long n,m,flag1=1,flag2=1,a[N],eq,cnt1=1,cnt2=1,plu,ans,cnt3;
bool cmp(long long q,long long w){
    return q>w;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((eq!=0)&&(eq!=(a[i]-a[i-1]))){
            flag2=0;
        }
        if(a[i]!=i){
            flag1=0;
        }
        if(i!=1){
            eq=a[i]-a[i-1];
        }
    }
    if(flag1){
        while(m>=cnt1&&cnt1<n){
            m-=cnt1;
            cnt1++;
        }
        cout<<cnt1;
        return 0;
    }else if(flag2){
        if(eq<0){
            long long x=-eq;
            eq=x;
        }
        while(m>=cnt2*eq&&cnt2<n){
            m-=cnt2*eq;
            cnt2++;
        }
        cout<<cnt2;
        return 0;
    }else{
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            cnt3=0;
            plu=0;
            if((n-i+1)<=ans){
                break;
            }
            while(m>=plu&&cnt3<n){
                cnt3++;
                plu+=a[i]-a[i+cnt3];
            }
            ans=max(ans,cnt3);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}