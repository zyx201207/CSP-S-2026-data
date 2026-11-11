#include<bits/stdc++.h>
#define F(i,a,b) for(int i = (a);i <= (b);i++)
#define D(i,a,b) for(int i = (a);i >= (b);i--)
using namespace std;
const int N = 200005;
int n,m,a[N],ans;
unordered_map<int,vector<int>>mp;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    F(i,1,n){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    D(i,a[n - m + 1],1){
        int ans = 0;
        F(j,1,n){
            if(a[j] & i == a[j]||a[j] & i == i){
                ans++;
            }
        }
        if(ans >= m){
            cout<< i << endl;
            return 0;
        }
        //cout<<ans<<' '<<i<<endl;
    }
    return 0;
}
