#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    bool a[4]={0};
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[0]=1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            a[1]=1;
            if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                    a[2]=1;
                    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')
                            a[3]=1;
            }
        }
    }
    for(int i=0;i<4;i++)cout<<a[i];
    return 0;
}
