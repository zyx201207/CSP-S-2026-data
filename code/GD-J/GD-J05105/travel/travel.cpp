#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","c",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==s1[0]||c1[1]==s1[1]||c2[0]==s2[0]||c2[1]==s2[1]||c2[2]==s2[2]+'1'||c2[2]==s2[2]+'2'){
		if(c2[2]=='C'||s2[2]=='D'){
			cout<<1100;
			return 0;
		}
		if(c2[2]=='A'||s2[2]=='B'){
			cout<<1111;
			return 0;
		}
		if(c2[2]=='B'||s2[2]=='C'){
			cout<<1111;
			return 0;
		}
		if(c2[2]=='D'||s2[2]=='F'){
			cout<<1111;
			return 0;
		}
	}
	if(c1[0]!=s1[0]||c1[1]!=s1[1]||c2[0]==s2[0]||c2[1]==s2[1]||c2[2]==s2[2]+'1'){
		if(c2[2]=='C'||s2[2]=='D'){
			cout<<0100;
			return 0;
		}
		if(c2[2]=='A'||s2[2]=='B'){
			cout<<0111;
			return 0;
		}
		if(c2[2]=='B'||s2[2]=='C'){
			cout<<0111;
			return 0;
		}
		if(c2[2]=='D'||s2[2]=='F'){
			cout<<0111;
			return 0;
		}
	}
	if(c1[0]!=s1[0]||c1[1]!=s1[1]||c2[0]!=s2[0]||c2[1]!=s2[1]||c2[2]!=s2[2]+'1'){
		cout<<0000;
		return 0;
	}
	
	if(c1[0]==s1[0]||c1[1]==s1[1]||c2[0]==s2[0]||c2[1]==s2[1]){
		if(c2[2]=='A'||s2[2]=='C'){
			cout<<1110;
			return 0;
		}
		else if(c2[2]=='C'||s2[2]=='A'){
			cout<<1110;
			return 0;
		}
		else{
			cout<<1100;
			return 0;
		}
	}
	if(c1[0]==s1[0]||c1[1]==s1[1]||c2[0]!=s2[0]||c2[1]==s2[1]||c2[2]==s2[2]+'1'||c2[2]!=s2[2]+'2'){
		if(c2[2]=='C'||s2[2]=='D'){
			cout<<0000;
			return 0;
		}
		else if(c2[2]=='A'||s2[2]=='B'){
			cout<<1000;
			return 0;
		}
		else if(c2[2]=='B'||s2[2]=='C'){
			cout<<1000;
			return 0;
		}
		else if(c2[2]=='D'||s2[2]=='F'){
			cout<<1000;
			return 0;
		}
		else if(c2[2]=='B'||s2[2]=='A'){
			cout<<1000;
			return 0;
		}
		else if(c2[2]=='C'||s2[2]=='B'){
			cout<<1000;
			return 0;
		}
		else if(c2[2]=='F'||s2[2]=='D'){
			cout<<1000;
			return 0;
		}
	}
	if(c1[0]!=s1[0]||c1[1]!=s1[1]||c2[0]!=s2[0]||c2[1]==s2[1]||c2[2]==s2[2]+'1'){
		if(c2[2]=='C'||s2[2]=='D'){
			cout<<0000;
			return 0;
		}
		if(c2[2]=='A'||s2[2]=='B'){
			cout<<0011;
			return 0;

		}
		if(c2[2]=='B'||s2[2]=='C'){
			cout<<0011;
			return 0;
		}
		if(c2[2]=='D'||s2[2]=='F'){
			cout<<0011;
			return 0;
		}
	}
	
	if(c1[0]==s1[0]||c1[1]==s1[1]||c2[0]==s2[0]||c2[1]==s2[1]||c2[2]==s2[2]+'1'||c2[2]==s2[2]+'2'){
		if(c2[2]=='C'||s2[2]=='D'){
			cout<<1100;
			return 0;
		}
		if(c2[2]=='A'||s2[2]=='B'){
			cout<<1111;
			return 0;
		}
		if(c2[2]=='B'||s2[2]=='C'){
			cout<<1111;
			return 0;
		}
		if(c2[2]=='D'||s2[2]=='F'){
			cout<<1111;
			return 0;
		}
	}
}
