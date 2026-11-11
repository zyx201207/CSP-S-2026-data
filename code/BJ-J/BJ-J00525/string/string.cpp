#include <bits/stdc++.h>
using namespace std;
int main(){
    
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    
    int m,n,a[100][100],s[1000],p,maxs = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 1000;j++){
                cin>>p;
                a[j][i] = p%2;
            }
    }for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 1000;j++){
            for(int x = 1;x <= j;x++){
                if(a[j][i] == a[j+x][i]){
                    for(int q = 1;q<=j;q++){
                            s[j] = s[j]+s[j]*2;
                    }
                }
            }
        }

    }for(int i = 1;i<=1000;i++){
        if(s[i]>maxs){
            maxs = s[i];
        }
    }
      cout<<maxs;
      return 0;
}
