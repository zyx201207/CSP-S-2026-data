#include<bits/stdc++.h>
using namespace std;
string s1,s2,r1,r2;
int c1,c2;
int a,b,sd[6]={1,1,1,2,0,2};
bool f1=0,f2=0,f3=0,f4=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    c1=s1[2]-'A';
    c2=s2[2]-'A';
    r1=s1.substr(0,2);
    r2=s2.substr(0,2);
    if(a==b)
    {
        f1=1;
        if(r1==r2){
            f2=1;
            if(sd[c1]==sd[c2]){
                f3=1;
                if(c1-c2==1||c1-c2==-1){
                    f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
