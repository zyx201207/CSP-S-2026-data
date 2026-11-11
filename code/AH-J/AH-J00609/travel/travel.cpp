#include<bits/stdc++.h>
using namespace std;
int judgelie(string l,string l1){
    if ((l == "A" || l == "B" || l == "C")  && (l1 == "A" || l1 == "B" || l1 == "C")) return 1;
    if ((l == "D" || l == "E")  && (l1 == "D" || l1 == "E")) return 2;
    return 0;
    }
int judgesame(string l,string l1){
    if ((l=="A")&&(l1=="C")) return 3;
    if ((l=="C")&&(l1=="A")) return 4;
    return 5;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2){
        cout << "0000";
    }
    else{
        cout << "1";
        string pai1 = s1.substr(0,2);
        string pai2 = s2.substr(0,2);
        string lie1 = s1.substr(2,1);
        string lie2 = s2.substr(2,1);
        if (pai1 == pai2){
            cout << "1";
            if(judgelie(lie1,lie2)==1){
                cout << "1";
                if(judgesame(lie1,lie2)==3 || judgesame(lie1,lie2)==4) cout << "0";
                else cout << "1";
            }
            else if(judgelie(lie1,lie2)==2){
                cout << "11";
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
