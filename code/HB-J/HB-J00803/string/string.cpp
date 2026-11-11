#include<bits/stdc++.h>
#define int long long
using namespace std;

struct str{
    int l,r;
    char c;
}s[200010];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,res=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        s[i].l=sum+1;
        cin>>a>>c;
        sum+=a;
        s[i].r=sum;
        s[i].c=c;
    }
    int pl=1,pr=n;
    for(int i=1;i<=sum/2;){
        i=min(s[pl].r,sum-s[pr].l+1);
        int pos=max(s[pl].l,sum-s[pr].r+1)-1;
        if(pl>=pr) break;
        if(s[pl].c!=s[pr].c){
            res+=min(s[pl].r,sum-s[pr].l+1)-pos;
        }
        if(s[pl].r>sum-s[pr].l+1){
            pr--;
        }else if(s[pl].r<sum-s[pr].l+1){
            pl++;
        }else{
            pr--;
            pl++;
        }
    }
    cout<<res;
    return 0;
}
