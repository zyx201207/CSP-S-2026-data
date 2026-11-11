#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ABC(char c){
    return c=='A'||c=='B'||c=='C';
}
bool XL(char a,char b){
    if(a=='F')a='E';
    if(b=='F')b='E';
    return abs(a-b)==1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(ABC(s1[2])^ABC(s2[2])){
                cout<<0<<0;
            }
            else{
                cout<<1;
                if(XL(s1[2],s2[2])){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
