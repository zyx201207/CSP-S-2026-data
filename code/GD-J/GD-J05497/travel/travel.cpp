#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s1;
string s2;
string s3;
string s4;
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s3){
		ll flag=0;
		for(int i=0;i<=1;i++){
			if(s2[i]!=s4[i]){
				cout<<0;
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<1;
		}
	}else{
		cout<<0;
	}
	if(s1==s3){
		ll flag=0;
		for(int i=0;i<=1;i++){
			if(s2[i]!=s4[i]){
				cout<<0;
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(s2[2]=='F'&&s4[2]=='D'){
				cout<<1;
			}else if(s2[2]=='D'&&s4[2]=='F'){
				cout<<1;
			}else if(s2[2]=='A'&&s4[2]=='B'){
				cout<<1;
			}else if(s2[2]=='B'&&s4[2]=='A'){
				cout<<1;
			}else if(s2[2]=='B'&&s4[2]=='C'){
				cout<<1;
			}else if(s2[2]=='C'&&s4[2]=='B'){
				cout<<1;
			}else if(s2[2]=='A'&&s4[2]=='C'){
				cout<<1;
			}else if(s2[2]=='C'&&s4[2]=='A'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	if(s1==s3){
		ll flag=0;
		for(int i=0;i<=1;i++){
			if(s2[i]!=s4[i]){
				cout<<0;
				flag=1;
				break;
			}
		}
		if(flag==0){
			if(s2[2]=='F'&&s4[2]=='D'){
				cout<<1;
			}else if(s2[2]=='D'&&s4[2]=='F'){
				cout<<1;
			}else if(s2[2]=='A'&&s4[2]=='B'){
				cout<<1;
			}else if(s2[2]=='B'&&s4[2]=='A'){
				cout<<1;
			}else if(s2[2]=='B'&&s4[2]=='C'){
				cout<<1;
			}else if(s2[2]=='C'&&s4[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
} 
