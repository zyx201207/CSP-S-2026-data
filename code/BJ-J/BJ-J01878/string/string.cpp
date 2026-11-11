#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    char c;
}a[200006];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].val>>a[i].c;
    }
    int l=1,r=n;
    long long ans=0;
    while (l<r){
        int v=min(a[l].val,a[r].val);
        a[l].val-=v;
        a[r].val-=v;
        if (a[l].c!=a[r].c)ans+=v;
        if (a[l].val<=0) l++;
        if (a[r].val<=0) r--;
    }
    cout<<ans;
    return 0;
}
