#include <bits/stdc++.h>
using namespace std;
long long n,sum;
struct point{
    long long x;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
    }
    long long l=0,r=n+1,dis=0,ans=0;
    while(l<r){
        if(dis==0){
            l++,r--;
            if(l>=r)break;
            if(a[l].c!=a[r].c){
                ans+=min(a[l].x,a[r].x);
            }
            dis=a[l].x-a[r].x;
        }
        if(dis<0){
            l++;
            if(l>=r)break;
            if(a[l].c!=a[r].c){
                ans+=min(a[l].x,-dis);
            }
            dis=a[l].x+dis;
        }
        if(dis>0){
            r--;
            if(l>=r)break;
            if(a[l].c!=a[r].c){
                ans+=min(a[r].x,dis);
            }
            dis=a[r].x-dis;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
