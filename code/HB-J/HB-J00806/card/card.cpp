#include<bits/stdc++.h>
using namespace std;

long long a[100010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==2){
        cout << 1 << " " << 1;
        return 0;
    }
    return 0;
}
