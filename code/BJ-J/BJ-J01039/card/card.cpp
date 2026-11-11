#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int js=0;
        for(int j=i;j<=n;j++){
            js++;
            if(a[j]!=a[j+1]){
                //cout<<j<<js<<' ';
                if(js%2==1){
                    b[a[j]]++;
                    //cout<<a[j-1];
                }
                js=0;
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
