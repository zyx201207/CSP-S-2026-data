#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
struct ttt{
    int t;
    char c;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].t>>a[i].c;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==2){
        if(a[1].c==a[2].c)cout<<0<<endl;
        else cout<<min(a[1].t,a[2].t)<<endl;
        return 0;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].c!=a[r].c)ans+=min(a[l].t,a[r].t);
        if(a[l].t==a[r].t)l++,r--;
        else if(a[l].t>a[r].t){
            a[l].t-=a[r].t;
            r--;
        }else{
            a[r].t-=a[l].t;
            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
