#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b) {
    if(a>b) swap(a,b);
    if(b==6) b--;
    if(a<=3) {
        if(b<=3) return true;
        else return false;
    }
    else if(a>=4)
        return true;
    return false;
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
        cout<<1;
    else cout<<0;
    if(check(s1[2]-'A'+1,s2[2]-'A'+1)&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
        cout<<1;
    else cout<<0;
    int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
    if(a>b) swap(a,b);
    if(b==6) b--;
    if((a+1)==b&&check(s1[2]-'A'+1,s2[2]-'A'+1)&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1;
    else cout<<0;
    cout<<"\n";
    return 0;
}
