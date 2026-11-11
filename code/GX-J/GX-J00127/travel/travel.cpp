#include <bits/stdc++.h>
using namespace std;

int a,b;
string n[4],m[4];
int main(){
    foren("travel.in","r",stdin);
    foren("travel.out","w",stdout);
    cin >> a >> n[4] >> b >> m[4];
    if(a==b){
        cout << 1;
        for(int i=0;i<=1;i++){
            for(n[i]==m[i]){
                cout << 1;
            }else{
                cout << 0;
            }
        }
    }else{
        cout << 0000;
    }
    return 0;
}
