//GZ-J00533 邓梓清 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>rc>>rs>>xc>>xs;
if(xc==rc)
cout<<1;
else cout<<0;
if(xc==rc&&rs[0]==xs[0]&&rs[1]==xs[1])
	cout<<1;
	else cout<<0;

if(xc==rc&&rs[0]==xs[0]&&rs[1]==xs[1]&&(((rs[2]>='A'&&rs[2]<'D')&&(xs[2]>='A'&&xs[2]<'D'))||((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F'))))
 cout<<1;	
else cout<<0;   
if(xc==rc&&rs[0]==xs[0]&&rs[1]==xs[1]&&(((rs[2]>='A'&&rs[2]<'D')&&(xs[2]>='A'&&xs[2]<'D')&&(rs[2]+1==xs[2]||xs[2]+1==rs[2]))||((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F')&&(rs[2]+2==xs[2]||xs[2]+2==rs[2]))))
 cout<<1;	
else cout<<0;       
	return 0;
} 
