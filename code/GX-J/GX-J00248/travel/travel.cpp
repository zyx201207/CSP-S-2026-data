#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c[5];
    int s[5];
    int t,r;

//int a[19] = {01,02,03,04,05,06,07,08,09,10,11,12,13,14,15,16,17,18};
char F,D,C,B,A;
 for(int i = 0;i<=2;i++)
 {
     cin>>c[5];
 }

 for(int j = 0;j<=2;j++)
 {
     cin>>s[5];
 }
cin>>r;
if(c[5-4] == s[5-4])
{
    cout<<"1";

}else{
cout<<"0"<<"0"<<"0"<<"0";
return 0;
}
if(c[5-3] == s[5-3])
{
    cout<<"1";
}else{
cout<<"0";
}
 if(c[5] == 'A' && s[5] == 'A')
 {
     cout<<"1";
 }
 else if(c[5] == 'A' && s[5] <= 'B')
 {
     cout<<"1";
 }
 else if(c[5] == 'B' && s[5] <= 'C')
 {
     cout<<"1";
 }
 else if(c[5] == 'C' && s[5] <= 'D')
 {
     cout<<"1";
 }
 else if(c[5] == 'D' && s[5] <= 'F')
 {
     cout<<"1";
 }
 else{

    cout<<"0";
 }
if(c[5]>='C' && s[5]>='C' || c[5]>='D' && s[5]>='D')
{
    cout<<"1";
}
else
{
    cout<<"0";
}

    return 0;
}
