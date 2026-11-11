#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans=1,last;
int num[N];
signed main(){
//int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+1+n);
    int l=1;
    for(int r=2;r<=n;r++){
        last+=(r-l)*(num[r]-num[r-1]);
        while(l<r && last>m){
            last-=num[r]-num[l];
            l++;
        }
        //cout<<l<<' '<<r<<endl;
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}
