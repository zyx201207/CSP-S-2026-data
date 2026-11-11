#include <bits/stdc++.h>
using namespace std;
//SASE! SASE! SASE!
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200001],maksand;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=(i+1);j<=n;j++){
            int andd=a[i];
            for(int k=i;k<=j;k++)
                andd=(andd&a[k]);
            if(andd>maksand)
                maksand=andd;
        }
    }
    cout<<maksand;
}
