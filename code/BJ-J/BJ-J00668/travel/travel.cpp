#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int t1=(s1[0]-'0')*10+s1[1]-'0';
    int t2=(s2[0]-'0')*10+s2[1]-'0';
    char q1=s1[2],q2=s2[2];
    if(c1==c2){
        if(t1==t2){
            if(q1>='A'&&q1<='C'){
                if(q2>='A'&&q2<='C'){
                    if(abs(q1-q2)==1) cout<<1111;
                    else cout<<1110;
                }
                else cout<<1100;
            }
            else{
                if(q2=='D'||q2=='F') cout<<1111;
                else cout<<1100;
            }
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
