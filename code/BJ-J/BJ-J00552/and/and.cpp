#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    while(n--){
        int maxn=m[a],maie=m[b];
        for(int i = 1; i <= n; i+=){
            if(maxn>m[i]){
                m[i] = maxn;
            }
            if(maie>m[i]){
                m[i] = maie;
            }
        }
    }cout << m[i] << endl;
    return 0;


}
