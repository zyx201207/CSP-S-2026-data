#include<bits/stdc++.h>
using namespace std;
string o1,s1,o2,s2;
int c1,c2,p1,p2;
char l1,l2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>o1>>s1>>o2>>s2;
    c1=o1[1]-'0'+(o1[0]-'0')*10;
    c2=o2[1]-'0'+(o2[0]-'0')*10;
    p1=s1[1]-'0'+(s1[0]-'0')*10;
    p2=s2[1]-'0'+(s2[0]-'0')*10;
    l1=s1[2];
    l2=s2[2];
    if(c1-c2)cout<<"0000";
    else{
        if(p1-p2)cout<<"1000";
        else{
            if(!(((l1=='A'||l1=='B'||l1=='C')&&(l2=='A'||l2=='B'||l2=='C'))||((l1=='D'||l1=='E')&&(l2=='D'||l2=='E'))))cout<<"1100";
            else{
                if(abs(int(l1-l2))<2)cout<<"1111";
                else cout<<"1110";
            }
        }
    }
    return 0;
}
