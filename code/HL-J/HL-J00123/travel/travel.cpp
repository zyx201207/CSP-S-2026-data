#include<bits/stdc++.h>
using namespace std;
int c1,c2,x[5];
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(x,0,sizeof(x));
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    if(c1 == c2 && c1!=16 && c1!=01){
        x[0] = 1;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        x[1] = 1;
    }
    for(int i = 0;i<4;i++){
        cout << x[i];
    }
    return 0;
}
