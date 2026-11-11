#include<bits/stdc++.h>
using namespace std;
bool yanzheng(char a,char b){
    if(b>'C'&&a<'D'){
        return 0;
    }else if(b<'D'&&a>'C'){
        return 0;
    }else {
        return 1;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,h1,c2,h2;
    char s1,s2;
    cin >> c1 >> h1 >> s1 >> c2 >> h2 >> s2;
    if(c1==c2){
      if(h1==h2){
           if(yanzheng(s1,s2)){
            if(((s1-s2)==1)||((s2-s1)==1)){
                cout << "1111";
            }else{
                cout << "1110";
            }
           }else{
           cout << "1100";
           }
            return 0;
      }else{
        cout << "1000";
        return 0;
      }
    }else{
    cout << "0000";
    return 0;
    }
    return 0;
}
