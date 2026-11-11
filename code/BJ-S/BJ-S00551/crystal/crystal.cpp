#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 5E5+10;
int n;
ll m,sum = 0;
ll a[N],gap[N];
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 2;i<=n;i++){
        gap[i] = a[i]-a[i-1];
    }
    int l = 1,ans = 0;
    for(int i = 1;i<=n;i++){
        sum += (i-l)*gap[i];
        if(sum > m){
            while(l<=m){
                if(sum<=m)break;
                else{
                    sum-=(a[i]-a[l]);
                    l++;
                }
            }
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
