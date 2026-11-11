#include<bits/stdc++.h>
using namespace std;

bool pd(char c1,char c2){
    if(c1>='A' && c1<='C' && c2>='A' && c2<='C')
        return 1;
    if(c1>='D' && c1<='F' && c2>='D' && c2<='F')
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2,a1=0,a2=0;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size()-1;i++)
        a1+=a1*10+(s1[i]-'0');
    for(int i=0;i<s2.size()-1;i++)
        a2+=a2*10+s2[i]-'0';
    if(c1==c2){
        if(a1==a2){
            if(pd(s1[2],s2[2])){
                if(s1[2]-1==s2[2] || s1[2]==s2[2]-1 || (s1[2]=='D' && s2[2]=='F') || (s2[2]=='D' && s1[2]=='F'))
                    printf("1111");
                else
                    printf("1110");
            }
            else
                printf("1100");
        }
        else
            printf("1000");
    }
    else
        printf("0000");
    return 0;
}
