#include <iostream>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans[5]={0};
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]=1;
	}else{
		ans[0]=0;
	}
	if(c1==c2){		
	if(s1[1]==s2[1]){
		ans[1]=1;
	}else{
		ans[1]=0;
	}
	
	}else{
		ans[1]=0;
	}
	
	if(ans[1]==1){
		
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='D'||s2[2]=='F'){
				ans[2]=0;
		}else{
				ans[2]=1;
		}	
	}
		if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			ans[2]=0;
		}else{
			ans[2]=1;
		}
	}
		
	}else if(ans[1]==0){
		ans[2]=0;
	}
	if(ans[1]==1){
		if(s1[2]=='A'&&s2[2]=='B'){
		ans[3]=1;	
		}else if(s1[2]=='B'&&s2[2]=='A'||s2[2]=='C'){
		ans[3]=1;
		}else if(s1[2]=='C'&&s2[2]=='B'){
		ans[3]=1;	
		}else if(s1[2]=='D'&&s2[2]=='F'){
		ans[3]=1;
		}else if(s1[2]=='F'&&s2[2]=='D'){
		ans[3]=1;
		}else{
		ans[3]=0;
		}
		}else{
		ans[3]=0;
		}
		cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	
	return 0;
}

