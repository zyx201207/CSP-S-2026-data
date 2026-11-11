#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else cout<<"0";
	
	int p=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		p=0;
	}else cout<<"0";
	
	if(p==1) {
		cout<<"0";
	}
		
	else {
		int a=s1[2]+s2[2];
		if(a-130==8) cout<<"1";
		else if(a-130<=3){
			cout<<"1";
		}
		else {
			cout<<"0";
			p=5;
		}
	}
	int b=abs(s1[2]-s2[2]);
	if(p==5) {
		cout<<"0";
	}
	else if(b==1){
		 cout<<"1";
	}
	else {
		cout<<"0";
	}
	
	
	return 0;
	
}



