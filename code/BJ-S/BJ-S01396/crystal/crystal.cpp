#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
ll a[maxn],n,q[maxn],m;
bool check(int x){
    /*
5 2
-3 -1 2 2 7
-3 -4 -2 0 7
    */
    //cout<<'*'<<x<<':';
    for(int i=x;i<=n;i++){
        /*
        cout<<i<<' '<<(ull)(a[x]*x)-(q[i]-q[i-x])<<' ';
        cout<<(ull)(a[x]*x)<<' ';
        //     ^      ^
        //      ll  a[i]
        cout<<q[i]<<' '<<q[i-x]<<'\n';
        */
        if((ll)(a[i]*x)-(q[i]-q[i-x])<=m){
            //cout<<"\n----true----\n";
            return 1;
        }
    }
    //cout<<"\n----fluse----\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //n=5e5,m=1e17;
    //max:0.1s nice
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //a[i]=(i&1?-1e12 : 1e12);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
