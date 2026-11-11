#include<bits/stdc++.h>
using namespace std;
long long n,len[200100],l,lmax,r,sum=0,sum1=0,ans=0;
char c[200100];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>len[i]>>c[i];
    l=1;
    r=n;
    while(l<r){
        if(len[l]>=len[r]){
            if(c[l]!=c[r])ans+=len[r];
            len[l]-=len[r];
            r--;
        }
        else{
            if(c[l]!=c[r])ans+=len[l];
            len[r]-=len[l];
            l++;
        }
    }
    cout<<ans;
    }
int main(){
    ios::sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
    }
