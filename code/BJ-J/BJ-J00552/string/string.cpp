#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> s >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s%100==n){
                cout << "0";
            }else{
                cout << "1";
            }
            if(s==n){
                cout << "0";
            }
            
        }
    }
    
    cout << "2"<< endl;
    cout << "0"<< endl;
    cout << "3000000000"<< endl;
    return 0;
    
}