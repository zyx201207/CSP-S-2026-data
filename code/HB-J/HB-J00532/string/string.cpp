#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[200005],t[200005],cnt;
string s;
char c[200005],ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        cin>>c[i];
        if(c[i]==c[i-1]){
            a[cnt]+=t[i];
            }
        else{
            a[++cnt]=t[i];
            ch[cnt]=c[i];
        }
    }
    int l=1,r=cnt;
    while(l<r){
        ans+=(min(a[l],a[r])*(bool)( !(ch[l]==ch[r]) ));
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else if(a[r]>a[l]){
            a[r]-=a[l];
            l++;
        }
        else{
            l++,r--;
        }
    }
    cout<<ans<<'\n';
}