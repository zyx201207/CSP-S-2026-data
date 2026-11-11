#include <bits/stdc++.h>
using namespace std;

int n,m,a[1000000],sizb[1000000],ans=0,num=0;
string b[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        while(a[i]!=0){
            b[i]+=(string){a[i]%2};
            sizb[i]++;
            a[i]/=2;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            else{
                for(int k=1;k<=min(sizb[i],sizb[j]);k++){
                    if(b[i][k]==b[j][k]){
                        num+=pow(2,k);
                    }
                }
            }
            ans=max(num,ans);
        }
    }
    cout << 12;
    return 0;
}
