//GZ-J00626 ÙFê–ÊÐÓ^É½ºþ…^ÆÕÈðŒWÐ£ ‡À¾¸‚Ü
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;cin>>a>>b>>a1>>b1;int c=int(b[2]-b1[2]);
	if(b[2]=='F')
		c-=1;
	if(b1[2]=='F')
		c+=1;
	if(a==a1)
		cout<<"1";
	else cout<<"0";
	if(b[0]==b1[0] && b[1]==b1[1] && a==a1)
		cout<<"1";
	else cout<<"0";
	if(b[0]==b1[0] && b[1]==b1[1] && a==a1 && ((b[2]<='C' && b1[2]<='C') || (b[2]>='D' &&b1[2]>='D')))
		cout<<"1";
	else cout<<"0";
	if(b[0]==b1[0] && b[1]==b1[1] && a==a1 && ((b[2]<='C' && b1[2]<='C') || (b[2]>='D' &&b1[2]>='D')) && ((c>0 && c<2) || (c<0 && c>-2)))
		cout<<"1";
	else cout<<"0";
	return 0;
} 
