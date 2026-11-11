//GZ-J00615 仇希臣
#include<iostream>
namespace std;
int main(){
    int c1,c2;
    string s1,s2;
    cin >>c1 >> s1 >>c2 >> s2;
    if (c1 == c2){
        cout << '1';
        if (s1[1] == s2[1] && s1[0] == s2[0]){
            cout << '1';
            if (s1[3] - s2[3] == 1 || s2[3] - s1[3] == 1){
                cout << '1';
                if ((s1[3] != 'C' && s2[3] != 'D') || (s1[3] != 'D' && s2[3] != 'C')){
                    cout << '1';
                }
                else{
                    cout << '0';
                }
            }
            else{
                cout << '00'
            }
        }
        else{
            cout << '000';
        }
    }
    return 0;
}
