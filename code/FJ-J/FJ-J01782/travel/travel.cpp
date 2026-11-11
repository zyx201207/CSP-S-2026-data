#include<bits/stdc++.h>
using namespace std;
struct seat{
	int xiang;
	int l;
	char s;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat a,b;
//	cin>>a.xiang>>a.l>>a.s;
//	cin>>b.xiang>>b.l>>b.s;
	if(a.xiang==b.xiang){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(a.l==b.l){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if((((a.s=='A')||(a.s=='B')||(a.s=='C'))&&((b.s=='A')||(b.s=='B')||(b.s=='C')))||(((a.s=='D')||(a.s=='E'))&&((b.s=='D')||(b.s=='E')))){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(((a.s-'0'-b.s-'0'==1 )||(b.s-'0'-a.s-'0'==1 ))&&((((a.s=='D'&&b.s=='E') )||(b.s=='D'&&a.s=='E'))||((a.s!='D')&&(b.s!='D'))) ){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}



