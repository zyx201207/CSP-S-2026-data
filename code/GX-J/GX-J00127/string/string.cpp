#include <bits/stdc++.h>
using namespace std;
int x;
int main(){
    foren("string.in","r",stdin);
    foren("string.out","w",stdout);
    cin >>x;
    int a[x];
    string b[x];
    for(int i=0;i<x;i++){
        cin >> a[i] >> b[i];
    }
    string c[x];
    for(int j=0;j<x;j++){
        c[j]=a[j]*b[j];
    }
    for(int o=0;o<x;o=o+2){
        string d=c[o]+c[o+1];
    }
    cout << 0;
    return 0;
}
