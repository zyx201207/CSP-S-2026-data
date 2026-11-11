# include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("travel.in","r","stdin");
    freopen ("travel.out","w","stdout");
    int c1,c2,c3,c4;
    cin >> c1 >> c2>>c3>>c4;
    if(c1/10==c3/10){
        cout << 1;
    }
    else {
        cout << 0;
    }
    if(c1%10==c3%10){
        cout << 1;
    }
    else{
        cout << 0;
    }



return 0;
}
