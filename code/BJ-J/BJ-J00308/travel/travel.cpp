#include <bits/stdc++.h>
using namespace std;
bool pd(string s1,string s2){
    char sub1=s1[2],sub2=s2[2];
    char maxx=max(sub1,sub2),minx=min(sub1,sub2);
    if (sub1>='A'&&sub1<='C'&&sub2>='A'&&sub2<='C') return 1;
    else if (sub1>='D'&&sub1<='F'&&sub2>='D'&&sub2<='F') return 1;
    else return 0;

}
bool pd2(string s1,string s2){
    char sub1=s1[2],sub2=s2[2];
    char maxx=max(sub1,sub2),minx=min(sub1,sub2);
    if ((int(maxx-minx)==1)) return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    if (c1==c2) cout <<1;
    else cout <<0;
    string r1=s1.substr(0,2),r2=s2.substr(0,2);
    if (c1==c2&&r1==r2) cout <<1;
    else cout <<0;
    if (c1==c2&&r1==r2&&pd(s1,s2)==1) cout <<1;
    else cout <<0;
    if (c1==c2&&r1==r2&&(r1==r2&&pd(s1,s2)==1)&&pd2(s1,s2)) cout <<1;
    else cout <<0;
    return 0;
}
