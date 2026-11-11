#include<bits/stdc++.h>
using namespace std;
bool is(char a,char b){
    if(a == 'A'){
        if(b == 'B'){
            return 1;
        }else{
            return 0;
        }
    }else if(a == 'B'){
        if(b == 'A' || b == 'C'){
            return 1;
        }else{
            return 0;
        }
    }else if(a == 'C'){
        if(b == 'B'){
            return 1;
        }else{
            return 0;
        }
    }else if(a == 'D' && b == 'F'){
        return 1;
    }else if(a == 'F' && b == 'D'){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    string r1,r2;
    for(int i = 0;i < s1.size()-1;i++){
        r1 += s1[i];
        r2 += s2[i];
    }
    char x1 = s1[2];
    char x2 = s2[2];
    if(c1 == c2){
        cout << 1;
        if(r1 == r2){
            cout << 1;
            if((x1 >= 'A' && x1 <= 'C' && x2 >= 'A' && x2 <= 'C') || (x1 >= 'D' && x1 <= 'F' && x2 >= 'D' && x2 <= 'F')){
                cout << 1;
                if(is(x1,x2)){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }else{
                cout << 0 << 0;
            }
        }else{
            cout << 0 << 0 << 0;
        }
    }else{
        cout << "0000";
    }
    return 0;
}
