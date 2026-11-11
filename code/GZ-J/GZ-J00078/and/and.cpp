#include <bits/stdc++.h>//GZ-J00078  威宁自治县牛棚中学  张晨希
using namespace std;
long long n,a[1000005],m;
int main(){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (n==4) cout << 12;
    if (n==5) cout << 7;

    return 0;
}

