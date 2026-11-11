#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool a(char a1,char a2){
    if(a1=='D'&&a2=='F'||a1=='A'&&a2=='B'||a1=='A'&a2=='C'||a1=='B'&&a2=='C')return 1;
    swap(a1,a2);
    return a1=='D'&&a2=='F'||a1=='A'&&a2=='B'||a1=='A'&a2=='C'||a1=='B'&&a2=='C';
}
bool b(char a1,char a2){
    if(a1=='D'&&a2=='F'||a1=='A'&&a2=='B'||a1=='B'&&a2=='C')return 1;
    swap(a1,a2);
    return a1=='D'&&a2=='F'||a1=='A'&&a2=='B'||a1=='B'&&a2=='C';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(a(s1[2],s2[2])){
                cout<<1;
                if(b(s1[2],s2[2])){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

