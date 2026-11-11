#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	bool ans[5];
	memset(ans,0,sizeof(ans));
	char s,t;
	cin>>a>>c>>s>>b>>d>>t;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else if(c!=d){
		cout<<"1000";
		return 0;
	}
	if(s=='A'){
		if(t=='B'){
			cout<<"1111";
			return 0;
		}
		else if(t=='C'){
			cout<<"1110";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else if(s=='B'){
		if(t=='A'||t=='C'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else if(s=='C'){
		if(t=='B'){
			cout<<"1111";
			return 0;
		}
		else if(t=='A'){
			cout<<"1110";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else if(s=='D'){
		if(t=='F'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	else{
		if(t=='D'){
			cout<<"1111";
			return 0;
		}
		else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
