#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2;
    string s1,s2;
    cin >> n1 >> s1 >> n2 >> s2;
    if(n1!=n2){
        cout << "0" << "0" << "0" << "0" << endl;
    }
    else{
        cout << "1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout << "1";
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    cout << "1";
                    if(s1[2]=='B'){
                        cout << "1" << endl;
                    }
                    else if(s2[2]=='B'){
                        cout << "1" << endl;
                    }
                    else{
                        cout << "0" << endl;
                    }
                }
                else{
                    cout << "0" << "0" << endl;
                }
            }
            else{
                if(s2[2]=='D'||s2[2]=='E'){
                    cout << "1" << "1" << endl;
                }
                else{
                    cout << "0" << "0" << endl;
                }
            }
        }
        else{
            cout << "0" << "0" << "0" << endl;
        }
    }
    return 0;
}
