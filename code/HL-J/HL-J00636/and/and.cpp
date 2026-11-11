#include <bits/stdc++.h>
using namespace std;
long n,m,l;
int s[100000];
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>l;
        while(l<2){
            s[i]=l%2;
            l/=2;
        }

    }



}
