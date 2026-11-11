#include <iostream>
using namespace std;
int c1,c2,s1[i][j] = [105][105],s2[i][j] = [105][105];
int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    cin >> c1 >> s1[i][j] >>c2 >> s2[i][j];
    if(c1 == c2 && c1 != '01' && c2 != '01' && c1 != '16' && c2 != '16'){
        cout << '1';
        if(s1[i] == s2[i]){
            cout << '1';
        }
        if(((s1[j] = 'A' || 'B' || 'C' )&&(s2[j] = 'A' || 'B'||'C'))&&((s1[j] = 'F' || 'D' )&&(s2[j] = 'F' ||'D'))){
            cout << '1';
        }
        if((s1[j] = 'A' && s2[j] = 'B') || (s1[j] = 'B' && s2[j] = 'c') || (s1[j] = 'D' && s2[j] = 'F')){
            cout << '1';
        }
    }
    else{
        cout << '0000';
    }
    return 0;
}
