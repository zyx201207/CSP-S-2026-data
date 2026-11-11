#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int L;
int l,r,sl,sr,n;
int j,dl,dr;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++)L+=a[i];
    l=1,r=0;
    sl=L+1,sr=0;
    j=n+1;
    int ans=0;
    int mid=(L+1)/2;;
    for(int i=1;i<=n;i++){
        r+=a[i];
        r=min(r,mid);
        
        while(l<=r){
            dr=L+1-l;
            dl=L+1-r;
            while(sl>dr){
                j--;
                sr=sl-1;
                sl=sl-a[j];
                sl=max(sl,L-mid-1);
            }
            if(c[i]!=c[j]){
                ans+=min(dr-sl+1,dr-dl+1);
            }
            sr=sr-min(dr-sl+1,dr-dl+1);
            l=l+min(dr-sl+1,dr-dl+1);
        }
        if(l>mid)break;
    }
    cout<<ans<<endl;
    return 0;
}