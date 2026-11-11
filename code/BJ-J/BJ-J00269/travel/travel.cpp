#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<0000;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(s1.substr(0,1)==s2.substr(0,1)) cout<<1;
    else{
        cout<<000;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='c') || ((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))) cout<<1;
    else{
        cout<<00;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='F' && s2[2]=='D')) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
