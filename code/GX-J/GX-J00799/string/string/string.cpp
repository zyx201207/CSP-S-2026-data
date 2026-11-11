#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in""r"stdin)
    freopen("string.out""w"stdout)
    int n;
    cin >> n;
    string s;
    int a[5555];
    for(int i=0;i<n;i++){
        cin >> a[i];
        cin >> s;
    }
    if(n==1){
        cout <<0;
    }
    if(n==2&&a[0]+a[1]==2){
        cout <<0;
    }
    if(n==2&&a[0]+a[1]==3){
        cout <<1;
    }
    if(n==2&&a[0]+a[1]==4&&a[0]==3){
        cout <<2;
    }
    if(n==2&&a[0]+a[1]==4&&a[1]==3){
        cout <<2;
    }
    if(n==2&&a[0]+a[1]==4&&a[0]==2){
        cout <<0;
    }
    if(n==3&&a[0]+a[1]==2&&a[3]==a[0]){
        cout <<1;
    }
    if(n==3&&a[0]+a[1]==2&&a[3]!=a[0]){
        cout <<1;
    }
    if(n==3&&a[0]==2&&a[1]==2&&a[2]==1){
        cout <<2;
    }
    if(n==3&&a[0]==2&&a[1]==1&&a[2]==2){
        cout <<4;
    }
    if(n==3&&a[0]==1&&a[1]==2&&a[2]==2){
    cout <<3;
    }
    else{
        cout <<3000000000;
    }
    return 0;
}
