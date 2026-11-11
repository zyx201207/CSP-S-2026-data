#include<bits/stdc++.h>
using namespace std;
const int mxn=300005;
int n;
int a[mxn];
char c[mxn];
long long ln,ans;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ln+=a[i];
    }
    long long l=1,r=ln;
    int cnter=1;
    for(int i=1,j=n,cnter=0;i<=j;){
        int mnl=min(a[i],a[j]);
//       cout<<i<<' '<<j<<' '<<mnl<<' '<<ans<<endl;
        if(c[i]!=c[j]){
//            cout<<"change"<<endl;
            ans+=mnl;
        }
        l+=mnl;
        r-=mnl;
        a[i]-=mnl;
        a[j]-=mnl;
        if(a[i]<=0){
            i++;
        }
        if(a[j]<=0){
            j--;
        }
    }
    cout<<ans<<cout;
}