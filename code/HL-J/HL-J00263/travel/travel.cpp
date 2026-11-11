#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int last1,last2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	// 1
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	// 2
	bool f=false;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		f=true;
	}
	else cout<<0;
	
	// 3
	char d1=s1[2];// ×ÖÄ¸1 
	char d2=s2[2];// ×ÖÄ¸2 
	if(f==false)cout<<0;
	else{
		//ÅÐ¶Ï²»Í¬Ò»²à 
		if(d1=='D'&&d2!='F' || d1=='F'&&d2!='D' || d2=='D'&&d1!='F' || d2=='F'&&d1=='D')cout<<0;
		
		else cout<<1;
	}
	// 4
	if(f==false){
		cout<<0;
		return 0;
	}
	if(( d1=='A'&&d2=='B' || d1=='B'&&d2=='C' || d1=='D'&&d2=='F') || (d2=='A'&&d1=='B' || d2=='B'&&d1=='C' || d2=='D'&&d1=='F' ))cout<<1;
	else cout<<0;
	return 0;
}
