#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m,a[MAXN],sub[MAXN];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    long long sym,op;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sub[i]=sub[i-1]+a[i];
    }
    int ans=0,ansop=2,j=n;
    for(int i=n;i>=1;i--){
        ansop--;
        while(true){
            if(j>0) j--;
            if(a[i]*(i-j+1)-sub[i]+sub[j-1]>m||j==0){
                if(ansop>ans) ans=ansop;
                j++;
                break;
            }
            ansop++;
        }
    }
    cout<<ans;
    return 0;
}
