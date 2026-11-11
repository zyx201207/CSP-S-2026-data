#include<bits/stdc++.h>
using namespace std;

int b[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        int g=a[i];
        int qg =g;
        for(int j=i+1;j<=n;j++){
            if(a[j]==g){
                g=qg;
            }
            else {
                qg=g;
                g=a[j];
            }
        }
        b[g]++;
        b[g-1]++;

    }
    for(int i=1;i<=m;i++){
        cout<<b[i];
    }

}
