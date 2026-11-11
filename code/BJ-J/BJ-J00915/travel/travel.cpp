#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool ans1=(c1==c2);
    bool ans2=ans1&&(s1[0]==s2[0])&&(s1[1]==s2[1]);
    int a=s1[2]-'A',b=s2[2]-'A';
    if(a>b)swap(a,b);
    bool ans4=ans2&&(a+1==b&&a!=2);
    bool ans3=ans2&&(ans4||(a==0&&b==2));
    cout<<ans1<<ans2<<ans3<<ans4;
}
