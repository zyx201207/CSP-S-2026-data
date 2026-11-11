#include <bits/stdc++.h>
using namespace std;

int const N = 500005;
int n,m,t,w;
int z[N];
int a[N];


void work(int x){
    for(int x = 1;x<=m;x++){
        if(z[x] < t && m >0){
            z[x] += 1;
            a[x] = z[x];
            m -= 1;
            }
        if(a[x] < t && a[x] != a[x-1]){
            w += 1;
        }
        }
    cout<<w;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>z[i];
        t += z[i];
    }
    t = t % n;
    work(m);
    return 0;
}
