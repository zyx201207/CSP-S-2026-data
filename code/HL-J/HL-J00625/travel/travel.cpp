#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i=1;i<=1;i++){
        if(c1==c2){
            cout << '1';
            if(s1[0]==s2[0]&&s1[1]==s2[1]){
                cout << "1";
                if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    cout << "1";
                    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
                        cout << "1";
                    }
                    else if(s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'){
                        cout << "1";
                    }
                    else{
                        cout << "0";
                        break;
                    }
                }
                else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
                    cout << "11";
                }
                else{
                    cout << "00";
                    break;
                }
            }
            else{
                cout << "000";
                break;
            }
        }
        else{
        cout << "0000";
        break;
        }
    }
    return 0;
}
