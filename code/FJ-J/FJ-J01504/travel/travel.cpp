#include<bits/stdc++.h>
using namespace std;
string a,b;
int c1,c2,p1,p2;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>c2>>b;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	p1=(a[0]-'0')*10+a[1],s1=a[2];
	p2=(b[0]-'0')*10+b[1],s2=b[2];
	if(s1<s2) swap(s1,s2);
	if(p1==p2) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if((s1-'0')-(s2-'0')<=2){
		if(s2=='C'&&(s1=='D'||s1=='F')){
			cout<<"00";
			return 0;
		}
		cout<<1;
	}
		
	else{
		cout<<"00";
		return 0;
	}
	if(abs((s1-'0')-(s2-'0'))==1) cout<<1;
	else cout<<0;
	return 0;
}//six seven!
