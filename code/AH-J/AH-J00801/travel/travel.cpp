#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int num=0;
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        num+=1000;
    }
    if((s1-'A'+1)==(s2-'A')||(s1-'A')==(s2-'A'+1))
    {
        num+=100;

    }
    if((s1-'A'<='C'&&s2-'A'<='C')||(s1-'A'>='D'&&s2-'A'>='D'))
    {
        num+=10;
    }
    if((s1-'A')-(s2-'A')==1||(s2-'A')-(s1-'A')==1)
    {
        num+=1;
    }
    cout<<num;
}
