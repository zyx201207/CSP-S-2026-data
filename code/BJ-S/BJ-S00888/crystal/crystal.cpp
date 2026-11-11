#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
int h[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll t,cnt=0,lst=0;
    for(int i=2;i<=n;i++){
        t=a[i];
        for(int j=1;j<i;j++){
            int e=a[j];
            while(e!=t){
                e++;
                cnt++;
            }
            if(cnt<=m){
                a[j]=e;
                lst=cnt;
            }else{
                cnt=lst;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        h[a[i]]++;
    }
    for(int i=1;i<N;i++){
        if(h[i]){
            ans=max(ans,h[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
