#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    char ss1=s1[2],ss2=s2[2];
    string pa1=""+s1[0]+s1[1],pa2=""+s2[0]+s2[1];
    if(pa1!=pa2){
        cout<<"1000\n";
        return 0;
    }
    if(ss1=='A' || ss1=='B' || ss1=='C'){
        if(ss2=='D' || ss2=='F'){
            cout<<"1100\n";
            return 0;
        }
        if(abs((ss1-'A')-(ss2-'A'))==1)cout<<"1111\n";
        else cout<<"1110\n";
        return 0;
    }
    if(ss1=='D'||ss1=='F'){
        if(ss2=='A' || ss2=='B' || ss2=='C'){
            cout<<"1100\n";
            return 0;
        }
        cout<<"1111\n";
        return 0;
    }
    return 0;
}
