#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,tg,l,r,L,ans,p,q,loop,i1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<ll>a(n+1);
    vector<char>s(n+1);
    for(int i=1;i<=n;i++)cin>>a[i]>>s[i],L+=a[i];
    i1=L%2;
    L/=2;
    for(;tg<n;tg++){
        if(L<a[tg])break;
        L-=a[tg];
    }
    l=r=tg;
    if(i1)a[tg]--;
    p=L,q=a[tg]-L;
    while(l&&r<=n){
        while(l>0&&q>=p){
            if(s[l]!=s[r])ans+=p;
            q-=p;
            l--;
            p=a[l];
        }
        if(l==0)break;
        while(r<=n&&p>=q){
            if(s[l]!=s[r])ans+=q;
            p-=q;
            r++;
            q=a[r];
        }
    }
    cout<<ans;
    return 0;
}
/*
6
1 a
1 b
1 c
1 d
2 e
1 f
*/