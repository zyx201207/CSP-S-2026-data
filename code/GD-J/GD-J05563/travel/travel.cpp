#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,a1,b,b1;
	string ans1="0",ans2="0",ans3="0",ans4="0";
	int c1=0,c2=0;
	cin>>a>>a1>>b>>b1;
	
	if(a[0]==b[0]) ans1="1";
	
	ans2="1";
	for(int i=0;i<2;i++){
		if(a1[i]!=b1[i]) ans2="0";
	} 
	 
	if(a1[2]=='A' or a1[2]=='B' or a1[2]=='C') c1=1;
	if(a1[2]=='D' or a1[2]=='F') c1=2;
	if(b1[2]=='A' or b1[2]=='B' or b1[2]=='C') c2=1;
	if(b1[2]=='D' or b1[2]=='F') c2=2;
	if(c1==c2) ans3="1";
	 
	if((a1[2]==b1[2]-1 or a1[2]-1==b1[2]) and ans3=="1") ans4="1";
	 
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
