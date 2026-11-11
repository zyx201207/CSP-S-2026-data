#include<bits/stdc++.h>
using namespace std;
string s1,t1,s2,t2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s1>>t1>>s2>>t2;
	
	if(t1[2]=='F')t1[2]='E';
	if(t2[2]=='F')t2[2]='E';
	
	if(s1!=s2)return cout<<"0000\n",0;
	if(t1[0]!=t2[0]||t1[1]!=t2[1])return cout<<"1000\n",0;
	if((t1[2]<='C')!=(t2[2]<='C'))return cout<<"1100\n",0;
	if(min(t1[2],t2[2])+1!=max(t1[2],t2[2]))return cout<<"1110\n",0;
	cout<<"1111\n";
	
	return 0;
}
