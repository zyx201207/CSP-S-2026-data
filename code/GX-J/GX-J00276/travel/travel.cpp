#include <bits/stdc++.h>
using namespace std;
string c1,p1,c2,p2;
int a=0,b=0,c=0,d=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>p1>>c2>>p2;
    if(c1==c2)a=1;
    if(a){
        string s1="",s2="";
            for(int i=0;i<=1;i++)s1+=p1[i];
            for(int i=0;i<=1;i++)s2+=p2[i];
        if(s1==s2){
            b=1;
        }
    }
    if(b){string s3="",s4="";
        s3+=p1[2],s4+=p2[2];
        int j1,j2;
        if(s3>="A"&&s3<="C")j1=1;
        else j1=2;
        if(s4>="A"&&s4<="C")j2=1;
        else j2=2;
        if(j1==j2){
            if(j1==j2==2)d=1;
            c=1;
        }
        if(c&&d==0){
            int f=abs(s3[0]-s4[0]);
            if(f==1)d=1;
            //cout<<f<<endl;
        }
    }
    cout<<a<<b<<c<<d<<endl;
    return 0;
}
