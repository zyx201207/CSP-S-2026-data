#include<bits/stdc++.h>
using namespace std;
string s,t,ss,tt;
map<char,int> q;
bool check(){
	return (s==ss);
}
bool checkk(){
	return check()&&(t[0]==tt[0])&&(t[1]==tt[1]);
}
bool checkkk(){
	return checkk()&&(q[t[2]]==q[tt[2]]);
}
bool checkkkk(){
	return (checkkk()&&(abs(t[2]-tt[2])==1));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    q['D']=1,q['F']=1;
    cin>>s>>t>>ss>>tt;
    cout<<check();
    cout<<checkk();
    cout<<checkkk();
    cout<<checkkkk();
   return 0;
}
//guan zhu luogu cp_zry
//mo ni pan duan
//wo chang chang zhui yi guo qu
//rp++
