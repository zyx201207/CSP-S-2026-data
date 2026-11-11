#include<bits/stdc++.h>
using namespace std;
int ii(string a,string b){
    if(a[0]==b[0] && a[1]==b[1]) return 1;
    return 0;
}
int iii(string a,string b){
    char x=a[2];
    char y=b[2];
    if(x<='C' && y<='C') return 1;
    if(x>='D' && y>='D') return 1;
    return 0;
}
int iiii(string a,string b){
    char x=a[2];
    char y=b[2];
    if(x=='A' && y=='B') return 1;
    if(x=='B' && y=='A') return 1;
    if(x=='B' && y=='C') return 1;
    if(x=='C' && y=='B') return 1;
    if(x=='D' && y=='F') return 1;
    if(x=='F' && y=='D') return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }
    else{
        cout<<"1";
        if(ii(s1,s2)==0){
            cout<<"000";
            return 0;
        }
        else{
            cout<<"1";
            if(iii(s1,s2)==0){
                cout<<"00";
                return 0;
            }
            else{
                cout<<"1";
                if(iiii(s1,s2)==0) cout<<"0";
                else{
                    cout<<"1";
                }
            }
        }
    }

    return 0;
}