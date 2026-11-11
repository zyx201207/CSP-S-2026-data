#include<bits/stdc++.h>
using namespace std;
const int mxn=500005;
int n;
long long mt;
long long a[mxn];
long long ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>mt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cnt=0,m=0;
    for(int i=1;i<=n;i++){
        cnt=1;
        m=mt;
        for(int j=i-1;j>=1;j--){
//            cout<<m<<' '<<a[i]<<' '<<a[j]<<' '<<cnt<<endl;
            if(m-(a[i]-a[j])>=0){
                m=m-(a[i]-a[j]);
                cnt++;
            }
            else{
                break;
            }   
        }
        ans=max(ans,cnt);
//        cout<<i<<' '<<cnt<<' '<<ans<<endl;
    }
    cout<<ans;
}