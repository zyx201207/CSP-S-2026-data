#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
map<char,int> m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    m['A']=1,m['B']=2,m['C']=3,m['D']=5,m['F']=6;
    if(c1!=c2)cout<<"0000";
    else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
    else if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))
    {
        if(abs(m[s1[2]]-m[s2[2]])!=1)cout<<"1110";
        else cout<<"1111";
    }
    else cout<<"1100";
    return 0;
}
