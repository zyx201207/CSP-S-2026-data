#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    bool b1,b2;
    int a[200005],n,ni,m,mi;
    char f[200005];
    cin>>n;
    b1=0;
    b2=0;
    for(int i=1;i<=n;i++){
        cin>>f[i]>>a[i];
        if(i>=2){
            if(f[i]!=f[i-1]){
                b1=1;
            }
        }
    }
    if(b1==0){
        cout<<"0";
    }
}
