#include<bits/stdc++.h>
using namespace std;

string c1,c2;
string s1,s2,n,m;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
        cout<<"0000"<<endl;
        return 0;
    }
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
        }
        else{
            cout<<"000";
            return 0;
        }
        n=s1[2];
        m=s2[2];
        if(n!=m&&n>="A"&&n<="C"&&m>="A"&&m<="C"){
            cout<<"1";
        }
        else if(n!=m&&(n=="D"||n=="F")&&(m=="F"||m=="D")){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        if(n!=m&&n>="A"&&n<="C"&&m>="A"&&m<="C"){
            if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"0";
        }

    }
    else{
        cout<<"0000"<<endl;
    }

    return 0;
}
