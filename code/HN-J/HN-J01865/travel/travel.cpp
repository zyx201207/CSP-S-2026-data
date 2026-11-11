#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c1,c2;
string s1,s2;
bool f(char c){
    return (c>='A'&&c<='C');
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        int x=s1[0]*10+s1[1],y=s2[0]*10+s2[1];
        if(x==y){
            if(f(s1[2])&&f(s2[2])){
                if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else if((f(s1[2])==0&&f(s2[2])==0)){
                cout<<"1111";
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
