#include<bits/stdc++.h>
using namespace std;

int c1,c2,si1,si2;
char sc1,sc2;
string s1,s2;
bool b[10];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c1>>s1>>c2>>s2;

    si1=(s1[0]-'0')*10+s1[1]-'0';
    sc1=s1[2];
    si2=(s2[0]-'0')*10+s2[1]-'0';
    sc2=s2[2];

    //cout<<"sc1="<<sc1<<",sc2="<<sc2<<",si1="<<si1<<",si2="<<si2<<"\n";

    if(c1!=c2){
        cout<<"0000";
    }
    else{
        if(si1!=si2){
            cout<<"1000";
        }
        else{
            if(sc1>='D'&&sc2<='C'||sc2>='D'&&sc1<='C'){
                cout<<"1100";
            }
            else{
                if((sc1-sc2)>1&&!(sc1=='D'&&sc2=='F')&&!(sc2=='D'&&sc1=='F')){
                    cout<<"1110";
                }
                else cout<<"1111";
            }
        }
    }
    return 0;
}
