#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,n,m,cnt,tmp;
    int c[2000005],d[200005];
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=b;i++){
        cin>>n>>m;
        for(int j=i;j<=n;j++){
            cin>>c[n];
        }
        for(int j=1;j<=n;j++){
            for(int r=j;r<=n;r++){
                if(j-r%3!=0){
                    if(j-r%m<=1)
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
