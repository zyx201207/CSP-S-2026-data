#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool chexiang=false;
	if(c1==c2) chexiang=true;
	bool pai=false;
	if(chexiang){
		if(s1[0]==s2[0] && s1[1]==s2[1]) pai=true;
	}
	bool ce=false;
	if(chexiang && pai){
		if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C')) ce=true;
		if((s1[2]>='D' && s1[2]<='F') && (s2[2]>='D' && s2[2]<='F')) ce=true;
	}
	
	bool xianglin=false;
	if(chexiang && pai && ce){
		if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s1[2]=='A')) xianglin=true;
		else if((s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s1[2]=='B')) xianglin=true;
		else if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s1[2]=='D')) xianglin=true;
	}
	if(chexiang) cout<<1;
	else cout<<0;
	if(pai) cout<<1;
	else cout<<0;
	if(ce) cout<<1;
	else cout<<0;
	if(xianglin) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
