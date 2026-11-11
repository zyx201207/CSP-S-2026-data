#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int c,T,T1;
void s(int c){

    cout <<rand()%300+T1<< "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> T;
    T1 = T;
    while(T--) s(c);
}
