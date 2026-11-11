#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
    mp['A']=1;mp['B']=1;mp['C']=1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char ss1,ss2;
    scanf("%d %d%c %d %d%c",&c1,&s1,&ss1,&c2,&s2,&ss2);
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1==s2) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(s1==s2 && mp[ss1]==mp[ss2]) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(s1==s2 && mp[ss1]==mp[ss2] && abs(ss2-ss1)<=1) cout<<1;
    else cout<<0;
    fclose(stdin);fclose(stdout);
    return 0;
}
