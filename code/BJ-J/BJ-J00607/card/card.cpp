#include <bits/stdc++.h>
using namespace std;
int a[500005];
 int main(){
    int n,m,y=0;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=n;i++){
    cin>>a[i];    
    }
    for(int j=1;j<=m;j++){
            y=j;
        for(int i=n,x=0;i>=0;i--){
            
            if(a[i]==y){
                cout <<n-x;
                y=n;
            }
            x++;
        }
        
    }



return 0;


 }
                  