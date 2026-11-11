#include<bits/stdc++.h>
using namespace std;
const N=1e5*5+8;
bool p[N];
int x[N];
int main(){
    freopen("migrate.in",r,stdin);
    freopen("migrate.out",w,stdout);
    int c,t,sum=0,m=0;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        sort(x+1,x+n+1);
        for(int j=1;j<=n;j++){
            m=x[j+2]-x[j];
            if(m<0){
                m=-m;
            }
            if(m<=d){
                sum++;
            }
        }
        sum=0;
    }

    return 0;
}
