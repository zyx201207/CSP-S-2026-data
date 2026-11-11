#include<iostream>
using namespace std;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a[5];
cin>>a[0]>>a[1]>>a[2]>>a[3];
int q=a[1][2];
int w=a[3][2];
if(a[0]==a[2]) cout<<'1';
else cout<<"0000";
if(a[1][0]==a[3][0] and a[1][1]==a[3][1]) cout<<'1';
else cout<<'0';
if(q<'D') 
{
	if(w<'D')
{
    cout<<'1';
    if(q-w==1 or w-q==1) cout<<'1';
    else cout<<'0';
}
}
if(q>='D') 
{
	if(w>='D')
{
    cout<<'1';
    if(q-w==1 or w-q==1) cout<<'1';
    else cout<<'0';
}
}
if(q>='D') 
{
	if(w<'D')
{ cout<<'0';
 cout<<'0';
}
}
if(q<'D') 
{
	if(w>='D')
{ cout<<'0';
 cout<<'0';
}

return 0;  
}
}
