#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=5010;
ll a[mx];
ll n,m,ans,maxans=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("ctystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        ll k=i-1,t=0;
        ans=1;
        while(k>0){
            if(t+(a[i]-a[k])>m) break;
            t+=a[i]-a[k];
            ans++;
            //cout<<a[i]<<" "<<a[k]<<" "<<ans<<'\n';
            k--;
        }
        //cout<<ans<<" "<<'\n';
        if(ans>maxans){
            maxans=ans;
        }
        if(maxans>=m) break;
    }cout<<maxans;
    return 0;
}
//My teacher doesn't teach me how do I write Dijbalabala(I forget it,sorry..)
//So I can't do anymore
//CCF is the best group(hhh
//And I don't learn the Tree and the Graph
//I will learn more!!!!
//I have long time,too!
/*
5 8
-3 -1 2 2 7
*/
