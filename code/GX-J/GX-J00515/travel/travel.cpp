#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,a2,a3,a4;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)a1=1;
    string a,b;
    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    char t1,t2;
        t1=s1[2];
        t2=s2[2];
    if(a==b&&a1==1)
        a2=1;

    if(a2==1&&t1>='A'&&t1<='C'&&t2>='A'&&t2<='C'||t1>='D'&&t1<='F'&&t2>='D'&&t2<='F'){
            a3=1;
            }
    if(abs(int (t1-t2))==1&&a3==1)a4=1;
    cout<<a1<<a2<<a3<<a4;
    return 0;


}
