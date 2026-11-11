//GZ-J00083 南明区山水中学 张皓宇
#include<bits/stdc++.h>
using namespace std;
bool a[10]={0};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) a[1]=1;
    else {cout<<"0000";return 0;}


    string a1;
    a1=s1[0]+s1[1];
    string a2;
    a2=s2[0]+s2[1];

    if(a1==a2)a[2]=1;
    else {cout<<"1000";return 0;}

     if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
        a[3]=1;
     }
     else{cout<<"1100";return 0;}

     if((s1[2]=='A'&&(s2[2]=='B'))||s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||(s1[2]=='C'&&(s2[2]=='B'))){
        a[4]=1;
        }
     else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
        a[4]=1;
     }
     else{cout<<"1110";return 0;}
     for(int i=1;i<=4;i++){
        cout<<a[i];
     }
    return 0;

}
