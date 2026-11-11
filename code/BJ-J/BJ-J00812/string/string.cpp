#include<bits/stdc++.h>
#define ll long long
using namespace std;//int
const ll MAXN=200005;
char c1[MAXN],c2[MAXN],c[MAXN];
ll a1[MAXN],a[MAXN],a2[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,x,sum=0;
    char t;
    scanf("%lld",&n);
    //cout << n;
    for(ll i = 1;i <= n;++i){
        scanf("%lld",&x);
        cin >> t;
        a[i]=x;c[i]=t;sum+=x;
        //cout << i << '\n';
    }
    //for(int i = 1;i <= n;++i){
    //    cout << (ll)a[i] << " " << c[i] << '\n';
    //}
    //cout << '\n';
    ll mid=(sum+1)/2,l1=0,l2=0;sum=0;
    //cout << mid << '\n';
    for(ll i = 1;i <= n;++i){
        x=a[i];t=c[i];
        if(sum+x<=mid){
            ++l1;
            a1[l1]=x;c1[l1]=t;
        }else if(sum>=mid){
            ++l2;
            a2[l2]=x;c2[l2]=t;
        }else{
            ++l1;++l2;//1000000000
            a1[l1]=mid-sum;x=x+sum-mid;c1[l1]=t;
            a2[l2]=x;c2[l2]=t;
        }
        sum+=x;
    }
    //for(ll i = 1;i <= l1;++i){
    //    cout << (ll)a1[i] << " " << c1[i] << '\n';
    //}
    //cout << '\n';
    //for(ll i = 1;i <= l2;++i){
    //    cout << (ll)a2[i] << " " << c2[i] << '\n';
    //}
    //cout << '\n';
    ll i=1,j=l2;sum=0;
    while(1){
        if(c1[i]==c2[j]){
            if(a1[i]==a2[j]){++i;--j;}
            else if(a1[i]>a2[j]){a1[i]-=a2[j];--j;}
            else{a2[j]-=a1[i];++i;}
        }else{
            if(a1[i]==a2[j]){sum+=a1[i];++i;--j;}
            else if(a1[i]>a2[j]){sum+=a2[j];a1[i]-=a2[j];--j;}
            else{sum+=a1[i];a2[j]-=a1[i];++i;}
        }
        if((j<1)||(i>l1)){break;}
    }
    printf("%lld",sum);
    return 0;
}
