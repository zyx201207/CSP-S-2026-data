#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int val;
    char c;
}a[200010];
int n,h,t,ans;
string s;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n,h=1,t=n;
    for(int i=1;i<=n;i++)cin>>a[i].val>>a[i].c;
    while(h<=t){
        if(a[h].c==a[t].c){
            if(a[h].val==a[t].val)h++,t--;
            if(a[h].val>a[t].val)a[h].val-=a[t].val,t--;
            if(a[h].val<a[t].val)a[t].val-=a[h].val,h++;
        }
        else{
            if(a[h].val==a[t].val)ans+=a[h].val,h++,t--;
            if(a[h].val>a[t].val)ans+=a[t].val,a[h].val-=a[t].val,t--;
            if(a[h].val<a[t].val)ans+=a[h].val,a[t].val-=a[h].val,h++;
        }
    }
    cout<<ans;
    return 0;
}
