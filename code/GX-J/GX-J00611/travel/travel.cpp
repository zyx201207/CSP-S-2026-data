#inclue<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2;
    string s1[1024]s2[1024];
    cin >> c1 >> s1;
    cin >> c2 >> s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(c1 == c2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1 == s2){
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(s1 + 1== s2 && s1 - 1 == s2){
        cout <<  "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
