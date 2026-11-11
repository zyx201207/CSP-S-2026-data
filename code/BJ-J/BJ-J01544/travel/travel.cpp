#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    m['A']=m['B']=m['C']=1;
    m['D']=m['F']=2;
    if(c1!=c2)
        cout<<"0000";
    else if(s1.substr(0,2)!=s2.substr(0,2))
        cout<<"1000";
    else{
        char a=s1[2],b=s2[2];
        if(m[a]!=m[b])
            cout<<"1100";
        else if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D')
            cout<<"1111";
        else
            cout<<"1110";
    }
    return 0;
}
