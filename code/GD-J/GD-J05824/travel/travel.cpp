#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	int h=b.size();
	for(int i=0;i<h;i++){
		if(b[i]==d[i]&&b[i+1]==d[i+1]){
		cout<<1;
		break;
	}
	else{
		cout<<"000";
		return 0;
	}
	}
	char o=b[h-1];
	char p=d[h-1];
	if(o=='A'&&p=='B'||o=='A'&&p=='C'||o=='B'&&p=='A'||o=='B'&&p=='C'||o=='C'&&p=='A'||o=='C'&&p=='B'||o=='D'&&p=='F'||o=='F'&&p=='D'){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(o=='A'&&p=='B'||o=='B'&&p=='A'||o=='B'&&p=='C'||o=='C'&&p=='B'||o=='D'&&p=='F'||o=='F'&&p=='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;	
}
