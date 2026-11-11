#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
    ll s;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    ll ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].s>a[r].s){
            if(a[l].c!=a[r].c){
                ans+=(a[r].s);
            }
            a[l].s-=a[r].s;
            a[r].s=0;
            r--;
        }else if(a[l].s<a[r].s){
            if(a[l].c!=a[r].c){
                ans+=(a[l].s);
            }
            a[r].s-=a[l].s;
            a[l].s=0;
            l++;
        }else if(a[l].s==a[r].s){
            if(a[l].c!=a[r].c){
                ans+=(a[l].s);
            }
            a[l].s=0;
            a[r].s=0;
            r--;
            l++;
        }
    }
    cout<<ans;
    return 0;
}
