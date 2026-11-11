#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m;
long long a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long cnt = 0,num = 1;
    while(m > 0){
        m -= num;
        num++;
        cnt++;
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
