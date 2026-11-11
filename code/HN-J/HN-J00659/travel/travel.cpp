#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char s1c,s2c;
    cin>>c1>>s1>>s1c>>c2>>s2>>s2c;
    vector<int>ans(4,0);
    if(c1==c2) {
        ans[0]=1;
        if(s1==s2) {
            ans[1]=1;
            if(s1c=='A'||s1c=='B'||s1c=='C') {
                if(s2c=='A'||s2c=='B'||s2c=='C') {
                    ans[2]=1;
                }
            }
            if(s1c=='D'||s1c=='E') {
                if(s2c=='D'||s2c=='E') {
                    ans[2]=1;
                }
            }
            if(s1c=='A'&&s2c=='B')ans[3]=1;
            if(s1c=='B'&&s2c=='C')ans[3]=1;
            if(s1c=='D'&&s2c=='E')ans[3]=1;
        }
    }
    for(int a:ans)cout<<a;

}
