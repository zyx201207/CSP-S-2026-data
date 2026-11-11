#include <bits/stdc++.h>
using namespace std;
string getnum(string s){
    string ans;
    for(int i=0;i<=1;++i){
        ans+=s[i];
    }
    return ans;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //string s;
    //cin >> s;
    //string ans=getnum(s);
    //cout << ans;
    //return 0;
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool samecar=0,samepai=0,sameside=0,lin=0;
    if(c1==c2){
        samecar=1;
        string row1=getnum(s1),row2=getnum(s2);
        //cout << row1 << " " << row2;
        if(row1==row2){
            samepai=1;
            char se1=s1[2],se2=s2[2];
            if((se1>='A'&&se1<='C'&&se2>='A'&&se2<='C')||(se1>='D'&&se1<='E'&&se2>='D'&&se2<='E')){
                sameside=1;
                if(se1-se2==1||se2-se1==1)  lin=1;
            }
        }
    }
    cout << samecar << samepai << sameside << lin;
    return 0;
}
