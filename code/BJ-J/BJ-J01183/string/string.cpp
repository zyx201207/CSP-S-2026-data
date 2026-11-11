#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n,ll=1,rl=a[n];
    while(l<=r){
        if(c[l]!=c[r])
            ans+=min(a[l]-ll+1,rl);
        if(a[l]-ll+1<rl){
            rl-=a[l]-ll+1;
            l++;
            ll=1;
        }else if(a[l]-ll+1>rl){
            ll+=rl;
            r--;
            rl=a[r];
        }else{
            l++;r--;
            ll=1,rl=a[r];
        }
    }
    cout<<ans<<endl;
    return 0;
}