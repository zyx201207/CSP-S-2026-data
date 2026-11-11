#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int extract(string s){
    int res=0;
    for(int i=0;i<s.size();i++) res=res*10+(s[i]-'0');
    return res;
}
bool check(char ch,char ch2){
    if(((ch=='A'||ch=='B'||ch=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))||((ch=='D'||ch=='F')&&(ch2=='D'||ch2=='F'))) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>c1>>c2;
    int snum=extract(s1);
    int cnum=extract(c1);
    char s=s2[2],c=c2[2];
    string spnum="",cpnum="";
    for(int i=0;i<2;i++){
        spnum+=s2[i];
        cpnum+=c2[i];
    }
    int snumm=extract(spnum),cnumm=extract(cpnum);
    if(snum==cnum&&snum!=1&&snum!=16){
        cout<<1;
        if(snumm==cnumm){
            cout<<1;
            if(check(s,c)){
                cout<<1;
                if(abs(s-c)==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    cout<<'\n';
    return 0;
}