#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c[N],a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int h=0,M=n,cnt=0,j=i+1;
        while(1){
            if(M-c[i]-h>=0){
                M-=c[i]+h;
                h=h*2+c[i];
                j++;
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}