#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct st{
    ll num;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)scanf("%lld %c",&a[i].num,&a[i].c);
    ll i=1,j=n,ans=0;
    while(i<=j){
        if(a[i].c!=a[j].c){
            if(a[i].num==a[j].num){
                ans+=a[i].num;
                i++;
                j--;
            }else if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                ans+=a[j].num;
                j--;
            }else if(a[j].num>a[i].num){
                a[j].num-=a[i].num;
                ans+=a[i].num;
                i++;
            }
        }else{
            if(a[i].num==a[j].num){
                i++;
                j--;
            }else if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                j--;
            }else if(a[j].num>a[i].num){
                a[j].num-=a[i].num;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
