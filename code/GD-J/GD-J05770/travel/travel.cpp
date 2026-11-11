#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;string s1,s2;
	cin>>n>>s1>>m>>s2;
	if(n==m)cout<<1;
	else{
		cout<<0;cout<<0;cout<<0;cout<<0;return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		cout<<0;cout<<0;cout<<0;return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<11;
		}else if(s2[2]=='C'){
			cout<<10;
		}else{
			cout<<00;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'){
			cout<<11;
		}else if(s2[2]=='C'){
			cout<<11;
		}else{
			cout<<00;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<11;
		}else if(s2[2]=='A'){
			cout<<10;
		}else{
			cout<<00;
		}
	}
	if(s1[2]=='E'){
		if(s2[2]=='F'){
			cout<<11;
		}else{
			cout<<00;
		}
	}
	if(s1[2]=='F'){
		if(s2[2]=='E'){
			cout<<11;
		}else{
			cout<<00;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
