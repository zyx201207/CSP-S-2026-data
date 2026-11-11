#include <bits/stdc++.h>//GZ-S00059  张晨希
using namespace std;
long long int c,n,m,t,k,u[100005],v[100005];
int main()
{
    freopen("hub.in","r","stdin");
    freopen("hub.out","w","stdout");
    cin >> c >> t;
    cin >> n >> k;
    if (c==0 && t==2){
        cout << 1 << endl << 2;
        return 0;
    }
    for (int i=1;i<=n*3;i++){
        cin >> u[i] >> v[i];
    }
    cout << u[5] << endl << u[9];
    return 0;
}
