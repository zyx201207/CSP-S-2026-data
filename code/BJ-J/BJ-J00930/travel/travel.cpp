#include<bits/stdc++.h>
using namespace std;
#define ll long long

string a1,a2,b1,b2;
ll ans1=0,ans2=0,ans3=0,ans4=0;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a1>>a2>>b1>>b2;

    if(a1==b1) ans1=1;
    if((a1==b1)&&((a2[0]==b2[0])&&(a2[1]==b2[1]))) ans2=1;
    if((((a1==b1)&&((a2[0]==b2[0])&&(a2[1]==b2[1])))) && (((a2[2]<='C')&&(b2[2]<='C')&&(a2[2]>='A')&&(b2[2]>='A')) || ((a2[2]>='D')&&(b2[2]>='D')))) ans3=1;
    if((((a1==b1)&&((a2[0]==b2[0])&&(a2[1]==b2[1])))) && (((a2[2]<='C')&&(b2[2]<='C')&&(a2[2]>='A')&&(b2[2]>='A')) || ((a2[2]>='D')&&(b2[2]>='D'))) && (((a2[2]-b2[2])==1||(a2[2]-b2[2])==1)||((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')))) ans4=1;
    cout<<ans1<<ans2<<ans3<<ans4<< "\n";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
