#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s1,s1a,s2,s2a;
	cin>>s1>>s1a>>s2>>s2a;
	if(s1[0]!='0'||s1[0]!='1'){
		cout<<"0000";
		return 0;
	}
	if(s1[2]>'8'){
		cout<<"0000";
		return 0;
	}
	if(s2[2]>'8'){
		cout<<"0000";
		return 0;
	}
	if(s2[0]!='0'||s2[0]!='1'){
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='0'&&s1[1]=='1'){
		cout<<"0000";
		return 0;
	}
	if(s1[0]=='1'&&s1[1]=='6'){
		cout<<"0000";
		return 0;
	}if(s2[0]=='0'&&s2[1]=='1'){
		cout<<"0000";
		return 0;
	}if(s2[0]=='1'&&s1[1]=='6'){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cout<<"0000";
			//cout<<"jl";
			return 0;
		}
	}
	cout<<1;
	//cout<<"jl";
	if(s1a[0]!=s2a[0]){
			cout<<"000";
			return 0;
	}
	if(s1a[1]!=s2a[1]){
			cout<<"000";
			return 0;
		}
	cout<<1;
	//cout<<"jl";
	if(s1a[2]=='A' ){
		if(s2a[2]=='B'){
			cout<<"11";
			return 0;
		}else if (s2a[2]=='C'){
			cout<<"10";
			return 0;
		}else if(s2a[2]=='D'||s2a[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	
	if(s1a[2]=='B' ){
		if(s2a[2]=='A'||s2a[2]=='C'){
			cout<<"11";
			return 0;
		}else if (s2a[2]=='D'||s2a[2]=='F'){
			cout<<"00";
			return 0;
		}
	}
	
	if(s1a[2]=='C' ){
		if(s2a[2]=='B'){
			cout<<"11";
			return 0;
		}else if (s2a[2]=='A'){
			cout<<"10";
			return 0;
		}else if(s2a[2]=='D' ||s2a[2]=='F'){
			//cout<<"jl";
			cout<<"00";
			return 0; 
		}
	}
	
	if(s1a[2]=='D' ){
		if(s2a[2]=='F'){
			cout<<"11";
			return 0;
		}else if (s2a[2]=='A'||s2a[2]=='B'||s2a[2]=='C'){
			cout<<"00";
			return 0;
		}
	}
	
	if(s1a[2]=='F' ){
		if(s2a[2]=='D'){
			cout<<"11";
			return 0;
		}else if (s2a[2]=='A'||s2a[2]=='B'||s2a[2]=='C'){
			cout<<"00";
			return 0;
		}
	}
	cout<<"0000";
	return 0;
}
