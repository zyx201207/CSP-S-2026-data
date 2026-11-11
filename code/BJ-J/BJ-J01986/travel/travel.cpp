#include<bits/stdc++.h>
using namespace std;
string a,c;
string b[3],d[3];
int main{
    ios::sync_with_stdio(flase);
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> c;
    if(a==c){
        cout << "1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout << "1";ge
            if(b[2]=="F" && d[2] == "D"){
            	cout << "11";
            }else if(b[2]=="D" && d[2] == "F"){
            	cout << "11";
            }else if(b[2]=="D" && d[2] != "F"){
            	cout << "00";
            }else if(b[2]=="F" && d[2] != "D"){
            	cout << "00";
            }else if(b[2]=="A" && d[2] == "B"){
            	cout << "11";
            }else if(b[2]=="A" && d[2] == "C"){
            	cout << "10";
            }else if(b[2]=="A" && d[2] == "D"){
            	cout << "00";
            }else if(b[2]=="A" && d[2] == "F"){
            	cout << "00";
            }else if(b[2]=="C" && d[2] == "B"){
            	cout << "11";
            }else if(b[2]=="C" && d[2] == "A"){
            	cout << "10";
            }else if(b[2]=="C" && d[2] == "D"){
            	cout << "00";
            }else if(b[2]=="C" && d[2] == "F"){
            	cout << "00";
            }else if(b[2]=="B" && d[2] == "A"){
            	cout << "11";
            }else if(b[2]=="B" && d[2] == "C"){
            	cout << "11";
            }else if(b[2]=="B" && d[2] == "D"){
            	cout << "00";
            }else if(b[2]=="B" && d[2] == "F"){
            	cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}