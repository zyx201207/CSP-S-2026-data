#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a[n+2];
    char b[n+2];
        string s,x;
    for(int i = 1;i <= n;i++){
        cin >>a[i];
        cin >> b[i];
         for(int j = 1;j<= a[i];j++)
            s += b[i];
    }
    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= a[ i ];j++){

            x+=b[i];
        }
    }
    //cout <<endl<< s <<endl<<x;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){

        }
    }
    return 0;
}
