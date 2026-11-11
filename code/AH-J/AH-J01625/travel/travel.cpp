#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f,ff,fff;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		fff=1;
	}
	else{
		cout<<0;
	}
	if(fff){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			ff=1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(ff){
		if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')){
			cout<<1;
			f=1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(f){
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			cout<<1;
		}
		else{
			cout<<0;
		} 
	}
	else{
		cout<<0;
	}
	return 0;
}
