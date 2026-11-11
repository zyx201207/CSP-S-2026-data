#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	int a=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			a=0;
		}
	}
	cout<<a;
	if(a){
		if((s1[2]=='A' and (s2[2]=='B' or s2[2]=='C'))or (s1[2]=='B' and (s2[2]=='A' or s2[2]=='C')) or (s1[2]=='C' and (s2[2]=='A' or s2[2]=='B'))){
			cout<<1;
			if(s1[2]=='A' and s2[2]=='B' or s1[2]=='B' and (s2[2]=='A' or s2[2]=='C') or s1[2]=='C' and s2[2]=='B'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if(s1[2]=='D' and s2[2]=='F' or s1[2]=='F' and s2[2]=='D'){
				cout<<1;
				cout<<1;
				
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
	}
	else{
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
