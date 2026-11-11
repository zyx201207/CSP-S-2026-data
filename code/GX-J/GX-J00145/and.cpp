#include <bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m,a,b=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        b=a;
        cnt=a&b;
    }
    cout<<max(cnt);
    return 0;
}


