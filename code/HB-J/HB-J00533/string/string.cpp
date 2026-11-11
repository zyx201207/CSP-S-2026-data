#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct str{
    ll num;
    char c;
};
ll n,ans,sum;
str a[200005];
char al;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        sum+=a[i].num;
    }
    for(ll i=1,j=n;i<=n;){
        if(a[i].c!=a[j].c){
            if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                ans+=a[j].num;
                a[j].num=0;
                j--;
            }else if(a[i].num==a[j].num){
                ans+=a[j].num;
                a[i].num=0;
                a[j].num=0;
                i++;j--;
            }else{
                a[j].num-=a[i].num;
                ans+=a[i].num;
                a[i].num=0;
                i++;
            }
        }else{
            if(a[i].num>a[j].num){
                a[i].num-=a[j].num;
                a[j].num=0;
                j--;
            }else if(a[i].num==a[j].num){
                a[i].num=0;
                a[j].num=0;
                i++;j--;
            }else{
                a[j].num-=a[i].num;
                a[i].num=0;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
