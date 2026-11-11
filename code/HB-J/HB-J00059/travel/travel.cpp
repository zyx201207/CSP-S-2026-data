#include <bits/stdc++.h>
using namespace std;

int v[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool flag=true;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) v[1]=1;
    else v[1]=0,flag=false;
    if(s1[1]==s2[1]&&flag==true) v[2]=1;
    else v[2]=0;
    if((abs(s1[2]-s2[2])<=2&&'A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||(abs(s1[2]-s2[2])==2)&&(s1[2]=='D'||s1[2]=='F')&&flag==true){
        if(v[2]==1) v[3]=1;
    }
    else v[3]=0;
    if(v[3]==1&&(abs(s1[2]-s2[2])==1&&'A'<=s1[2]&&'C'>=s1[2]&&'A'<=s2[2]&&'C'>=s2[2])||(abs(s1[2]-s2[2])==2)&&(s1[2]=='D'||s1[2]=='F')&&flag==true){
        v[4]=1;
    }
    else v[4]=0;
    for(int i=1;i<=4;i++){
        cout << v[i];
    }
    return 0;
}
