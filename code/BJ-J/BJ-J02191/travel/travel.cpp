#include<bits/stdc++.h>
using namespace std;
map<pair<char,char>,bool> chk;
void add(char ch1,char ch2){
    chk[make_pair(ch1,ch2)]=true;
}
bool check(char ch1,char ch2){
    return chk[make_pair(ch1,ch2)]||chk[make_pair(ch2,ch1)];
}
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    add('D','F');
    add('A','B');
    add('A','C');
    add('B','C');

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="0000";
    if(c1==c2){
        ans[0]='1';
        string d1=s1.substr(0,2);
        string d2=s2.substr(0,2);
        if(d1==d2){
            ans[1]='1';
            char p1=s1[2];
            char p2=s2[2];
            if(check(p1,p2)){
                ans[2]='1';
                if(!((p1=='A'&&p2=='C')||(p1=='C'&&p2=='A'))){
                    ans[3]='1';
                }
            }
        }
    }
    //cout<<c1<<s1<<c2<<s2<<"\n";
    cout<<ans;

    return 0;
}
