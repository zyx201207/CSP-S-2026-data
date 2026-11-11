#include <bits/stdc++.h>
using namespace std;
enum class line:int{A,B,C,D,F};
struct sit{
    int column;
    line l;
};
pair<bool,bool> check(line a,line b){
    int ua=(int)a,ub=(int)b;
    pair<bool,bool> answer;
    answer.first=(ua<3 ? (ub<3) : (ub>2));
    answer.second=((ua>ub ? ua-ub : ub-ua)==1);
    return answer;
}
void sitin(string ch,sit& s){
    int c;char l;
    line ls;
    c=stoi(ch.substr(0,ch.size()-1));
    l=ch[ch.size()-1];
    switch (l){
        case 'A':ls=line::A;break;
        case 'B':ls=line::B;break;
        case 'C':ls=line::C;break;
        case 'D':ls=line::D;break;
        case 'F':ls=line::F;break;
        default:break;
    }
    s.column=c;
    s.l=ls;
}
int c1,c2;
sit s1,s2;
void input(string cache,int& cnt){
    if (cnt==0) c1=stoi(cache);
    else if (cnt==2) c2=stoi(cache);
    else if (cnt==1) sitin(cache,s1);
    else sitin(cache,s2);
}
bool ans[4];
string in;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,in);
    int cnt=0;char last;
    string cache;
    for (auto i:in){
        if (i==' ') {
            if (last!=' '){
                input(cache,cnt);
                cnt+=1;
                cache="";
            }
            continue;
        }
        else if (i=='0') continue;
        else cache+=i;
        last = i;
    }
    if(in[in.size()-1]!=' ')input(cache,cnt);
    ans[0] = (c1==c2);//chexiang
    ans[1] = (s1.column==s2.column)&&ans[0];//pai
    auto c=check(s1.l,s2.l);
    ans[2]=c.first&&ans[1];ans[3]=c.second&&ans[2];
    for (auto k:ans) cout<<k;
    return 0;
}
