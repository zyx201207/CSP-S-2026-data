#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
long long ans;
char c[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    int kl=1,rl=n,l=a[1],r=a[n];
    while(kl<rl){
        if(l==r){
            if(c[kl]!=c[rl])ans+=l;
            l=a[++kl];
            r=a[--rl];
        }else if(l<r){
            if(c[kl]!=c[rl])ans+=l;
            r-=l;
            l=a[++kl];
        }else{
            if(c[kl]!=c[rl])ans+=r;
            l-=r;
            r=a[--rl];
        }
    }
    cout<<ans;
    return 0;  
}