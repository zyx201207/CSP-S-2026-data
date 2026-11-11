#include <bits/stdc++.h>
using namespace std;
int a,b,c[999999],d,lb,lz;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<b;i++) cin>>c[i];
    for(int i=0;i<b;i++){
            lb=c[i];
        for(int j=0;j<b;j++){
            if(d+1==b){
                if(lb>lz) lz=lb;
                d=0;
                j=j+2-b;
                lb=c[i];
            }
            lb=lb&c[j];
            d++;
    }

    }
    cout<<lz;
    return 0;
}
