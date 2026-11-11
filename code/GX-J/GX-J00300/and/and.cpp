#include <bits/stdc++.h>
using namespace std;
int idk[56342];
int save_and[7000];
int main(){
    freopen("and2.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,Mx=-2;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> idk[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            save_and[i]=idk[i] & idk[j];
    }
    for(int i=0;i<n;i++){
        if(Mx<save_and[i]){
            Mx = save_and[i];
        }
    }
    cout << Mx;
    return 0;
}
