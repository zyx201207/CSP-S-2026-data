#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long a[MAXN],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long temp=1,t=m;
        for(int j=i-1;j>=1;j--){
            if(t<a[i]-a[j]) break;
            else{
                t-=(a[i]-a[j]);
                temp++;
            }
        }
        ans=max(ans,temp);
    }
    cout << ans << endl;
    return 0;
}
