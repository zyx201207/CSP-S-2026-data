#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
string c1,s1,c2,s2;
ll check(char a){
    if(a=='D' || a=='F')return 2;
    return 1;
}
bool ch(char a,char b){
    if(a<b)swap(a,b);
    if(a-b==1 || (a-b==2 && check(a)==2 && check(b)==2)){
        return 1;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if(check(s1[s1.size()-1])==check(s2[s2.size()-1])){
                cout<<1;
                if(ch(s1[s1.size()-1],s2[s2.size()-1]))cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
