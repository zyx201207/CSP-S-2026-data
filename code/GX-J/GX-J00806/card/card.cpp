#include<bit/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int pai[n+5];
    for(int i=0;i<n,i++){
        cin>>pai[i];
    }
    int a=0,b=0,c=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            for(int x=0;x<j;x++){
                if(a[i]==a[j-x]){
                    a[j-x];
                }
            }
        }
    }

    return 0;
}
