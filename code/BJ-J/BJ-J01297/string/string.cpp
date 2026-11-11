#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int num;
    char c;
};
int n;
int ans;
node a[200005];
signed main(){
    freopen("string .in","r",stdin);
    freopen("string .out","w",stdout);
    cin>>n;
    int f=1,l=n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].num>>a[i].c;
    }
    while(f<l)
    {
        if(a[f].num==0) f++;
        if(a[l].num==0) l--;
        int minn=min(a[f].num,a[l].num);
        if(a[f].c==a[l].c) {
            a[f].num-=minn;
            a[l].num-=minn;
        }
        else{
            ans+=minn;
            a[f].num-=minn;
            a[l].num-=minn;
        }
        if(a[f].num==0) f++;
        if(a[l].num==0) l--;
    }
    cout<<ans;
    return 0;
}
