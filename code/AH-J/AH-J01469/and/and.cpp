#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int m,n,maxn=0,f;
    cin >> n >> m;
    long long s[n];
    for (int i=0;i<n;i++){
        cin >> s[i];
    }
    if (m==2){
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                f=s[i]&s[j];
                maxn=max(maxn,f);
            }
        }
    }else{
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                for (int z=j;z<n;z++){
                    f=s[i]&s[j]&s[z];
                    maxn=max(maxn,f);
                }
            }
        }
    }
    cout << maxn;
    return 0;
}
