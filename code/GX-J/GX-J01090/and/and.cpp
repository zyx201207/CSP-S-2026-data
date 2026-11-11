#include <bits/stdc++.h>
using namespace std;

bool com(long long a,long long b){
    return a > b;
}

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    long n,m;
    cin >> n >> m;
    long long a[n+5];
    int c[n+5];
    for(int i = 0;i<n;i++){
        cin >> a[i];
        int c1 = 0;
        int c2 = a[i];
        while (c2>0){
            c2 /= 2;
            c1++;
        }
        c[i] = c1;
    }
    sort(a,a+n,com);
    sort(c,c+n,com);


}
