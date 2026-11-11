#include<bits/stdc++.h>
#define re register
using namespace std;
inline bool left(string x){
    if(x[2] == 'A' || x[2] == 'B' || x[2] =='C'){
        return 1;
    }
    else return 0;
}
inline bool chex(string x,string y){
    for(re int i = 0;i < 2;i ++){
       if(x[i] != y[i]){
          return 1;
       }
    }
    return 0;
}
inline bool seat(string x,string y){
    for(re int i = 0;i < 2;i ++){
        if(x[i] != y[i]){
            return 1;
        }
    }
    return 0;
}
inline bool leftorright(string x,string y){
    if(left(x) == left(y)){
        return 0;
    }
    else return 1;
}
inline bool Nextto(string x,string y){
    if(x[2] == 'D' && y[2] == 'F') return 0;
    if(x[2] + 1 == y[2] || x[2] - 1 == y[2]){
        return 0;
    }
    return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag = 0;
    flag = chex(c1,c2);
    if(flag == 1){
        cout << "0000" << endl;
        return 0;
    }
    else cout << '1';
    flag = seat(s1,s2);
    if(flag == 1){
        cout << "000" << endl;
        return 0;
    }
    else cout << '1';

    flag = leftorright(s1,s2);
    if(flag == 1){
        cout << "00" << endl;
        return 0;
    }
    else cout << '1';
    flag = Nextto(s1,s2);
    if(flag == 1){
        cout << '0' << endl;
    }
    else cout << '1';
    cout << endl;
	return 0;
}
