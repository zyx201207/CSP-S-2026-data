#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

string ss1,sz1,ss2,sz2;

//cheng xv shu chu
string shuchunr = "";

//qi qv pai hao
string tqph(string shuru){
    string s = ""; // bian li chu shu zi bu fen  bian li zai s zhong

    for(int i = 0;i < shuru.length()-1;i++){
        s = s+shuru[i];
    }

    return s;
}

//ti qv zuo hao A F
//string tqzh(string shuru){
//    return shuru[shuru.length()-1];
//}

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;



    if(c1 == c2){
        shuchunr = shuchunr+"1";
    }
    else{
        shuchunr = shuchunr+"0";
    }

    if(c1 == c2 && tqph(s1) == tqph(s2)){
        shuchunr = shuchunr+"1";
    }
    else{
        shuchunr = shuchunr+"0";
    }

    if(c1 == c2 && tqph(s1) == tqph(s2)){
        shuchunr = shuchunr+"1";
    }
    else{
        shuchunr = shuchunr+"0";
    }

    if(c1 == c2 && tqph(s1) == tqph(s2)){
        shuchunr = shuchunr+"1";
    }
    else{
        shuchunr = shuchunr+"0";
    }

    cout << shuchunr;


    return 0;
}
