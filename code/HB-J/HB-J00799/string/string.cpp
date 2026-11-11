#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int cnt;
int lef,righ;
pair<int,char>a[205000];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    lef=1;
    righ=n;
    int ans=0;
    while(lef<righ){
        if(a[lef].first<a[righ].first){
            int k=a[lef].first;
            a[righ].first-=k;
            if(a[lef].second!=a[righ].second){
                ans+=k;
            }lef++;
        }
        else if(a[lef].first==a[righ].first){
            int k=a[lef].first;
            if(a[lef].second!=a[righ].second){
                ans+=k;
            } lef++;righ--;
        }
        else{
             int k=a[righ].first;
            a[lef].first-=k;
            if(a[lef].second!=a[righ].second){
                ans+=k;
            }righ--;
        }
    }
    cout<<ans;
    return 0;
}
