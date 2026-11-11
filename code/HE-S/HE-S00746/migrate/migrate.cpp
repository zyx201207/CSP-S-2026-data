#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen(migrate.in,"r",stdin);
    freopen(migrate.out,"w",stdout);
    int c,t,n,d,x[100005],two=0;
    cin>>c>>t>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(n>=4&&d>=1){
            if(x[n-1]-4==0){
                two=1;
            }else if(x[n-i]-4>0){
                two++;
            }
        cout<<two;
        }
    }
    return 0;
}


