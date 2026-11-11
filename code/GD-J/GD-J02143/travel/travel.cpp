#include<bits/stdc++.h>
using namespace std;
struct p{
	int a;
	string st;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.a>>a.st>>b.a>>b.st;
	if(a.a==b.a){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a.st[0]==b.st[0]&&a.st[1]==b.st[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a.st[2]=='A'||a.st[2]=='B'||a.st[2]=='C'){
		if(b.st[2]=='A'||b.st[2]=='B'||b.st[2]=='C'){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
		if(b.st[2]==a.st[2]+1||b.st[2]==a.st[2]-1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		if(b.st[2]=='D'||b.st[2]=='F'){
			cout<<11;
		}
		else{
			cout<<"00";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
