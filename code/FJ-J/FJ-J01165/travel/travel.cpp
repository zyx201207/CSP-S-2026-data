#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	
	char a=c2[2],b=c4[2];
	
	if(c1==c3)cout<<1;
	else cout<<0;
	
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1])cout<<1;
	else cout<<0;
	
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&a<='C'&&b<='C')cout<<1;
	else if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&(a>='D'&&a<='F')&&(b>='D'&&b<='F'))cout<<1;
	else cout<<0;
	
	if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&a<='C'&&b<='C'&&(a-1==b||a+1==b))cout<<1;
	else if(c1==c3&&c2[0]==c4[0]&&c2[1]==c4[1]&&(a>='D'&&a<='F')&&(b>='D'&&b<='F')&&(a-1==b||a+1==b))cout<<1;
	else cout<<0;
	cout<<"\n";
	
	return 0;
}
