#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2;
string s1,s2;
bool ch1(char ch){
    return ('A'<=ch&&ch<='C');
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    int p1=(s1[0]-'0')*10+s1[1]-'0';
    int p2=(s2[0]-'0')*10+s2[1]-'0';
    char t1=s1[2],t2=s2[2];
    if(c1!=c2) cout<<"0000";
    else if(p1!=p2) cout<<"1000";
    else if((ch1(t1)&&!ch1(t2))||(ch1(t2)&&!ch1(t1))) cout<<"1100";
    else if(abs(t1-t2)>1) cout<<"1110";
    else cout<<"1111";
    return 0;
}