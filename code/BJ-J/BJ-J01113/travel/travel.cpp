#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
string ccc[4];
char s1,s2;
int solve(char s){
    return (s=='D'||s=='E');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ccc[0]>>ccc[1]>>ccc[2]>>ccc[3];
    a1=(ccc[0][0]-'0')*10+(ccc[0][1]-'0');
    b1=(ccc[1][0]-'0')*10+(ccc[1][1]-'0');
    s1=ccc[1][2];
    a2=(ccc[2][0]-'0')*10+(ccc[2][1]-'0');
    b2=(ccc[3][0]-'0')*10+(ccc[3][1]-'0');
    s2=ccc[3][2];
    if(a1==a2){
        cout<<1;
        if(b1==b2){
            cout<<1;
            if(solve(s1)+solve(s2)!=1){
                cout<<1;
                if(abs((int)(s2-s1))==1){
                    cout<<1<<endl;
                }else{
                    cout<<"0"<<endl;
                }
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }
}
