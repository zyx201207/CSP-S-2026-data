//GZ-J00492 遵义市第十六中学 何世灏 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool st=1;
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]) st=0;
	}if(st) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s2[2]<='C' && s4[2]<='C'){
		cout<<1;
		if(abs(s4[2]-s2[2])==1) cout<<1;
		else cout<<0;
	} 
	else if(s2[2]>'C' && s4[2]>'C'){
		cout<<1;
		if(abs(s4[2]-s2[2])==1) cout<<1;
		else cout<<0;
	} 
	else cout<<0<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
