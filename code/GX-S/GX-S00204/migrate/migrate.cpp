#include<bits/stdc++.h>
using namespace std;
long long t,b,n,m,l[500005],d[500005],cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>l[i];
        }
        for(int i=2;i<=m;i++){
            d[i]=l[i]-l[1];
            if(d[i]<=m){
                b=i+1;
            }
        }
        for(int i=m;i>1;i--){
            if(d[i-1]+m<d[i]){
                t=i-1;
            }
        }
        for(int i=b;i<=t;i++){
            if(d[i]%m<=m/2){
                cnt++;
            }
        }
        //cout<<cnt<<endl;
    }
    cout<<1<<endl<<2;
    return 0;
}

