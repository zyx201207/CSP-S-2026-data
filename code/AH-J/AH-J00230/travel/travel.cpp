#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+5;

string s1,s2,s3,s4;
string d[10] = {"AB","BC","DF"};

void init(){
    cin>>s1>>s2>>s3>>s4;   
    // cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<"\n"; 
}

int sign(char a){
    return a-'A'+1;
}

bool is(string o){
    for(int i=0;i<3;i++){
        if(d[i]==o)return true;
    }
    return false;
}

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    init();

    // return 0;
    // 1
    if(s1==s3)cout<<1;
    else cout<<0;

    // cout<<"|"<<s2[0];
    string k1 = "",k2 = "";
    k1 += s2[0]+s2[1];
    k2 += s4[0]+s4[1];

    //2
    if(s1==s3 && k1==k2)cout<<1;
    else cout<<0;

    int p1 = sign(s2[2]);
    int p2 = sign(s4[2]);

    // cout<<p1<<" "<<p2<<"\n";

    // 3
    if(s1==s3 && k1==k2 && ((p1<=3 && p2<=3) || (p1>3 && p2>3)))cout<<1;
    else cout<<0;

    string h = "";
    // h+= s2[2] + s4[2];
    h+= s2[2];
    h+=s4[2];

    // cout<<"\n"<<h<<"\n";

    //4
    if(s1==s3 && k1==k2 && ((p1<=3 && p2<=3) || (p1>3 && p2>3)) && is(h))cout<<1;
    else cout<<0;

    return 0;
}