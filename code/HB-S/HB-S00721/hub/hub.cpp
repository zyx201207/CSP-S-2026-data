#include <bits/stdc++.h>
using namespace std;
int a[500000+10][500000+10];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,t;
    int n,k;
    cin>>c>>t;
    for(int i=0;i<c;i++){
        for(int j=0;j<t;j++){
        cin>>a[i][j];
        }
    }
    sort(a,a+n);
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
        cout<<1<<endl<<2;

        }
    }

    return 0;
    }
