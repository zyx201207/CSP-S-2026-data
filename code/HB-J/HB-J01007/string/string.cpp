#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    For(i,1,n)cin>>a[i]>>c[i];
    long long x=1,y=n,ans=0;
    while(x<y){
        long long cnt=min(a[x],a[y]);
//        cout<<cnt<<endl;
        a[x]-=cnt;
        a[y]-=cnt;
        if(c[x]!=c[y])ans+=cnt;
        if(a[x]==0)x++;
        if(a[y]==0)y--;
//        cout<<x<<" "<<y<<endl;
//        cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
