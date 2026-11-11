#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long m;
int ans=0;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt1=n;
    int maxn;
    sort(a+1,a+n+1);
    for(int i=1;i<=cnt1;i++){
        int ans1=0;
        long long cnt=m;
        vector<int> b(cnt1+1);
        maxn=a[cnt1];
        for(int j=1;j<=cnt1;j++){
            b[j]=maxn-a[j];
        }
        for(int j=cnt1;j>=1;j--){
            cnt-=b[j];
            if(cnt<=0){
                break;
            }
            ans1++;
        }
        if(cnt>0) ans1-=1;
        cnt1-=1;
        ans=max(ans,ans1);
        cnt=m;
    }
    cout<<ans+1;
    return 0;
}
