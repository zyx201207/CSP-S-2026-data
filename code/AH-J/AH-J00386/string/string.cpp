#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=200002;
struct node{
    ll l=0,r=0,k=0;
    char f;
}a[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,bn,w=1;
    cin>>bn;
    n=bn;
    for(int i=1;i<=bn;i++){
        ll ls;
        cin>>ls>>a[w].f;
        if(a[w].f==a[w-1].f){
            a[w-1].r+=ls;
            a[w-1].k+=ls;
            n--;
        }
        else{
            a[w].l=a[w-1].r+1;
            a[w].r=a[w-1].r+ls;
            a[w].k=ls;
            w++;
        }
    }
    ll left=1,right=n,ans=0;
    while(1){
        node x=a[left],y=a[right];
        if(x.k>y.k){
            if(x.f!=y.f)ans=ans+y.k;
            x.k-=y.k;
            x.l+=y.k;
            a[left]=x;a[right]=y;
            right--;
        }
        else if(x.k<y.k){
            if(x.f!=y.f)ans=ans+x.k;
            y.k-=x.k;
            y.r-=x.k;
            a[left]=x;a[right]=y;
            left++;
        }else{
            if(x.f!=y.f)ans=ans+x.k;
            a[left]=x;a[right]=y;
            left++;
            right--;
        }
        if(left>right)break;
    }
    cout<<ans;
    return 0;
}
//8:57~9:43 0->100
