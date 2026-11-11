#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
bool isnear(char a, char b){
    if(a==b) return false;
    if(b<a) swap(a, b);//a<b
    return (a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F');
}bool issame(char a, char b){
    if(b<a) swap(a, b);//a<b
    return (a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='A'&&b=='C')||(a=='D'&&b=='F');
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, a1, c2, a2;
    cin>>c1>>a1>>c2>>a2;
    string s1 = a1.substr(0, 2), s2 = a2.substr(0, 2);
    char x1 = a1[2], x2 = a2[2];
    //cout<<c1<<' '<<s1<<' '<<x1<<' '<<c2<<' '<<s2<<' '<<x2<<endl;
    if(c1!=c2){
        cout<<"0000"<<endl;
    }else{
        if(s1!=s2){
            cout<<"1000"<<endl;
        }else{
            if(!issame(x1, x2)){
                cout<<"1100"<<endl;
            }else{
                cout<<"111"<<isnear(x1, x2)<<endl;
            }
        }
    }
}