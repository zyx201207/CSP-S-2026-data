#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("in.travel","r",stdin);
	freopen("out.travel","w",stdout);
	string c1,s1,c2,s2;
	long long n=0,m=0,f=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1==s2){
		cout<<"000";
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			n=1;
			break;
		}
	}
	if(n==0){
		cout<<1;
	}
	if(n==1){
		cout<<"000";
	}
	else {
		if(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D'){
			cout<<11;
			return 0;
		}
		else if(s2[s2.size()-1]=='F'&&s1[s1.size()-1]=='D'){
			cout<<11;
			return 0;
		}
		else if(s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C'){
			cout<<1;
			m=1;
			if(s1[s1.size()-1]=='A'&&s2[s2.size()-1]=='B'){
				cout<<1;
				return 0;
			}
			else if(s1[s1.size()-1]=='B'&&s2[s2.size()-1]=='C'){
				cout<<1;
				return 0;
			}
			else if(s2[s2.size()-1]=='A'&&s1[s1.size()-1]=='B'){
				cout<<1;
				return 0;
			}
			else if(s2[s2.size()-1]=='B'&&s1[s1.size()-1]=='C'){
				cout<<1;
				return 0;
			}
		}
		if(s1[s1.size()-1]>'C'||s2[s2.size()-1]>'C'){
		cout<<"00";
		} 
	}
	if(m==1){
		cout<<0;
	}
	return 0;
}
