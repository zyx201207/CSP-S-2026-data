#include <bits/stdc++.h>
using namespace std;
long long a,n,e,d;
char c;
char c1[30];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int a1[n];
    for (long long b;b<=n;b++){
        cin >> a >> c ;
        a1[b]==a;
        c1[b]==c;
    }
    for(long long e=n;e>0;e--){
            for (long long b;b<=n;b++){
                if(c1[e]==c1[b]){
                    cout << d;
                }
            }
    }
    return 0;
}
