#include <bits/stdc++.h>
using namespace std;
int an[1000000];
map<int,int> f[200001];
int main(){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    bool ok=1,bo=1;
    for(int i=1;i<=a;i++){
        cin>>an[i];
        f[i][0]=an[i];
            if(an[i]!=i-1){
                ok=0;
            }
            if(an[i]!=pow(2,i)-1){
                bo=0;
            }
    }
    if(ok){
        cout<<an[a-b+1];
        return 0;
    }
    if(bo){
        cout<<an[a-b+1];
        return 0;
    }
    for(int i=1;i<b;i++){
        for(int j=1;j<=a;j++){
            for(int k=j-1;k>0;k--){
                    if(f[j][i]==0){
                        f[j][i]=f[j][i-1]&f[k][i-1];
                        continue;
                    }
                f[j][i]=max(f[k][i-1]&f[j][i-1],f[j][i]);
            }
                   // cout<<f[j][i]<<'\n';
        }
    }
    int da=-1;
    for(int i=1;i<=a;i++){
        da=max(da,f[i][b-1]);
    }
    cout<<da;
    return 0;
}
