#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else if(a!=c){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i+1<b.size();i++){
		if(b[i]==d[i]){
			ans++;
		}
	}
	if(ans==2){
		cout<<"1";
	}
	else if(ans!=2){
		cout<<"000";
		return 0;
	}
	for(int i=2;i<b.size();i++){
		if(b[i]=='A'||b[i]=='B'||b[i]=='C'){
			if(d[i]=='A'||d[i]=='B'||d[i]=='C'){
				cout<<"1";
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			if(d[i]=='D'||d[i]=='F'){
				cout<<"1";
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		if(b[i]=='A'){
			if(d[i]=='B'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else if(b[i]=='B'){
			if(d[i]=='A'||d[i]=='C'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else if(b[i]=='C'){
			if(d[i]=='B'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else if(b[i]=='D'){
			if(d[i]=='F'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
		else{
			if(d[i]=='D'){
				cout<<"1";
				return 0;
			}
			else{
				cout<<"0";
				return 0;
			}
		}
	}
	
	return 0;
}
