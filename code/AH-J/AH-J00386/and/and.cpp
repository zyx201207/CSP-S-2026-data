#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=200005;
typedef long long ll;
ll a[N],pf[N],n,m,ans=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    pf[0]=1;
    for(int i=1;i<32;i++)pf[i]=pf[i-1]*2;
    for(int i=32;i>=0;i--){
        int l=0;
        for(int j=1;j<=n;j++){
            if(a[j]>=pf[i]){
                l++;
            }
        }
        if(l>=m){
            ans+=pf[i];
            for(int j=1;j<=n;j++)a[j]-=pf[i];
        }
    }
    cout<<ans;
    return 0;
}
//9:43~10:12 0->100
