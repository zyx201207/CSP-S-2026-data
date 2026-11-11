#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    int first_car = (s1[0]-'0')*10+(s1[1]-'0');
    int second_car = (s3[0]-'0')*10+(s3[1]-'0');
    int first_line = (s2[0]-'0')*10+(s2[1]-'0');
    int second_line = (s4[0]-'0')*10+(s4[1]-'0');
    char first_seat = s2[2];
    char second_seat = s4[2];
    if(first_car != second_car){
        cout << "0000";
    }else{
        if(first_line != second_line){
            cout << "1000";
        }else{
            if(first_seat == 'A' && second_seat == 'B'){
                cout << "1111";
            }else if(first_seat == 'A' && second_seat == 'C'){
                cout << "1110";
            }else if(first_seat == 'A' && second_seat == 'D'){
                cout << "1100";
            }else if(first_seat == 'A' && second_seat == 'F'){
                cout << "1100";
            }else if(first_seat == 'B' && second_seat == 'A'){
                cout << "1111";
            }else if(first_seat == 'B' && second_seat == 'C'){
                cout << "1111";
            }else if(first_seat == 'B' && second_seat == 'D'){
                cout << "1100";
            }else if(first_seat == 'B' && second_seat == 'F'){
                cout << "1100";
            }else if(first_seat == 'C' && second_seat == 'A'){
                cout << "1110";
            }else if(first_seat == 'C' && second_seat == 'B'){
                cout << "1111";
            }else if(first_seat == 'C' && second_seat == 'D'){
                cout << "1100";
            }else if(first_seat == 'C' && second_seat == 'F'){
                cout << "1100";
            }else if(first_seat == 'D' && second_seat == 'A'){
                cout << "1100";
            }else if(first_seat == 'D' && second_seat == 'B'){
                cout << "1100";
            }else if(first_seat == 'D' && second_seat == 'C'){
                cout << "1100";
            }else if(first_seat == 'D' && second_seat == 'F'){
                cout << "1111";
            }else if(first_seat == 'F' && second_seat == 'A'){
                cout << "1100";
            }else if(first_seat == 'F' && second_seat == 'B'){
                cout << "1100";
            }else if(first_seat == 'F' && second_seat == 'C'){
                cout << "1100";
            }else if(first_seat == 'F' && second_seat == 'D'){
                cout << "1111";
            }
        }
    }
    return 0;
}
