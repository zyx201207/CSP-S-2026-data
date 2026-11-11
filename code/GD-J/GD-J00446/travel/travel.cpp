#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int c1,c2,si1,si2,ss1,ss2;
string s1,s2;

bool check(int a,int b){
    if(a <= 2 && b <= 2) return true;
    if(a>2 && b>2) return true;
    return false;
}

int main(){
     freopen("travel.in","r",stdin);
     freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>c1>>s1>>c2>>s2;
    si1 = (s1[0]-'0')*10+(s1[1]-'0');
    si2 = (s2[0]-'0')*10+(s2[1]-'0');
    ss1 = s1[2]-'A';
    ss2 = s2[2]-'A';
    if(c1 != c2){
        cout<<"0000";
    }else if(si1 != si2){
        cout<<"1000";
    }else if(!check(ss1,ss2)){
        cout<<"1100";
    }else if(abs(ss1-ss2) != 1){
        cout<<"1110";
    }else cout<<"1111";

    return 0;
}
