#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++)cin >> a[i];
        int q=abs(a[2]-a[1]);
        int fly=d/q;
        cout << n-fly-1 << endl;
    }
}
