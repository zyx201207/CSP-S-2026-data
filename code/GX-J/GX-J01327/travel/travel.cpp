#include<bits/stdc++.h>
using namespace std;
bool bl1(char a){return a=='A'||a=='B'||a=='C';}
bool bl2(char a){return a=='D'||a=='F';}
char ma[2][6]={{'B','C','A','B','D','F'},{'C','B','B','A','F','D'}};
bool mt(char a,char b){
    for(int i=0;i<6;i++)if(a==ma[0][i]&&b==ma[1][i])return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    char a=s1[2],b=s2[2];
    cout<<(c1==c2);
    cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1]));
    cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&((bl1(a)&&bl1(b))||(bl2(a)&&bl2(b))));
    cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&mt(a,b));
    return 0;
}
