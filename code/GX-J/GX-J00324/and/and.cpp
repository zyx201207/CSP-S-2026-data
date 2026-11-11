#include <bits/stdc++.h>
using namespace std;
int sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;cin>>n>>m;int sz[n];
    for(int i=0;i<n;i++) {cin>>sz[i];//cout << op[i];
    }


    for(int i=0;i<n;i++){
            int kksk=sz[i];
        for(int j=1;j<m;j++){
                if(i+j<=n)kksk=(kksk&sz[i+j]);
        }sum=max(sum,kksk);
        if(i>2001) break;
    }
    cout << sum;
    return 0;
}
