#include <iostream>
using namespace std;
long long ans;
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int maxn,minn;
    long long a[100005];

    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++){
        long long x;
        for(int j=i;j<=n;j++){
            x = (a[i] & a[j]);
            ans = max(ans,x);
        }
    }
    cout << ans << endl;
    return 0;
}
