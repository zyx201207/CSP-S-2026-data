#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int MAXN=5*1e5+5;
int a[MAXN];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    bool dengcha=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]==a[i-1]-a[i-2]){
            continue;
        }
        else{
            dengcha=0;
        }
    }

    if(dengcha){
        int ans=0;
        for(int i=1;i<=n;i++){
            m-=a[i]-a[1];
            if(m>=0){
                ans++;
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    sort(a+1,a+n+1);
    int ans=-1;
    for(int i=1;i<=n;i++){
        int r=m;
        int num=0;
        for(int j=i;j>=1;j--){
            if(abs(a[i]-a[j])<=r){
                num++;
                r-=abs(a[i]-a[j]);
            }
            else{
                break;
            }
        }
        ans=max(ans,num);
    }

    cout<<ans<<endl;

    return 0;
}
