#include<bits/stdc++.h>
using namespace std;
long long x[2000000];
int query(int s,int e,int d){
    int ans = 0;
    if(x[e] - x[s] < d){
        ans++;
        return ans;
    }
    if(e - s == 1) return ans;
    for(int i = s+1;i < e;i++){
        ans += query(s,i,d)*query(i,e,d);
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    long long d;
    int ans;
    int q;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 0;i < n;i++){
            cin >> x[i];
        }
        ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                q = query(i,j,d);
                cout << i << ' ' << j << ' ' << q << endl;
                if(q == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
