#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int t[130],b[130];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    t['A']=1;t['B']=2;t['C']=3;
    b['A']=b['B']=b['C']=1;
    b['D']=b['F']=2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else{
        if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
        else if(b[s1[2]]!=b[s2[2]])cout<<"1100";
        else if(abs(t[s1[2]]-t[s2[2]])!=1)cout<<"1110";
        else cout<<"1111";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
