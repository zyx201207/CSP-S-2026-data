#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=0;
	if(c1==c2){
		cout<<1;
		flag=1;
	}else{
		cout<<0;
	}
	if(!flag){
		cout<<0;
	}else{
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			flag=1;
			cout<<1;
		}else{
			cout<<0;
			flag=0;
		}
	}
	if(!flag){
		cout<<0;
	}else{
		if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
			cout<<1;
		}else{
			flag=0;
			cout<<0;
		}
	}
	if(!flag){
		cout<<0;
	}else{
		if(s1[2]==s2[2]+1 || s1[2]+1==s2[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
