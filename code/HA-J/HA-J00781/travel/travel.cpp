#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int ans1,ans2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	for(int i=0;i<c.size();i++){
		ans1=ans1*10+c[i]-'0';
	}
	for(int i=0;i<cc.size();i++){
		ans2=ans2*10+cc[i]-'0';
	}
	if(ans1!=ans2){
		cout<<"0000";
		return 0;
	}
	ans1=ans2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')ans1=ans1*10+s[i]-'0';
	}
	for(int i=0;i<ss.size();i++){
		if(ss[i]>='0'&&ss[i]<='9')ans2=ans2*10+ss[i]-'0';
	}
	if(ans1!=ans2){
		cout<<"1000";
		return 0;
	}
	char s1,s2;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z')s1=s[i];
	}
	for(int i=0;i<ss.size();i++){
		if(ss[i]>='A'&&ss[i]<='Z')s2=ss[i];
	}
	if(s1=='A'){
		if(s2=='B'){
			cout<<"1111";
		}else if(s2=='C'){
			cout<<"1110";
		}else if(s2=='D'){
			cout<<"1100";
		}else if(s2=='F'){
			cout<<"1100";
		}
	}else if(s1=='B'){
		if(s2=='A'){
			cout<<"1111";
		}else if(s2=='C'){
			cout<<"1111";
		}else if(s2=='D'){
			cout<<"1100";
		}else if(s2=='F'){
			cout<<"1100";
		}
	}else if(s1=='C'){
		if(s2=='B'){
			cout<<"1111";
		}else if(s2=='A'){
			cout<<"1110";
		}else if(s2=='D'){
			cout<<"1100";
		}else if(s2=='F'){
			cout<<"1100";
		}
	}else if(s1=='D'){
		if(s2=='B'){
			cout<<"1100";
		}else if(s2=='C'){
			cout<<"1100";
		}else if(s2=='A'){
			cout<<"1100";
		}else if(s2=='F'){
			cout<<"1111";
		}
	}else if(s1=='F'){
		if(s2=='B'){
			cout<<"1100";
		}else if(s2=='C'){
			cout<<"1100";
		}else if(s2=='A'){
			cout<<"1100";
		}else if(s2=='D'){
			cout<<"1111";
		}
	}
	return 0;
}
