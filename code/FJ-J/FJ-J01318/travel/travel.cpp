#include<bits/stdc++.h>
using namespace std;
	string c1,s1,c2,s2;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=3,m=2;
	for(int i=1;i<=m;i++){cin>>c1[i];}
	for(int i=1;i<=n;i++){cin>>s1[i];}
	for(int i=1;i<=m;i++){cin>>c2[i];}
	for(int i=1;i<=n;i++){cin>>s2[i];}
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<1;
		if(s1[1]==s2[1]&&s1[2]==s2[2]&&s1[3]!=s2[3]){
			cout<<1;
			if(s1[3]=='A'){ 
				if(s2[3]=='B'||s2[3]=='C'){
					cout<<1;
					if(s2[3]=='B'){
						cout<<1;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}	
			if(s1[3]=='B'){
				if(s2[3]=='C'||s2[3]=='A'){
					cout<<1<<1;return 0;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			if(s1[3]=='C'){
				if(s2[3]=='B'||s2[3]=='A'){
					cout<<1;
					if(s2[3]=='B'){
						cout<<1;
						return 0;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			if(s1[3]=='D'){
				if(s2[3]=='F'){
					cout<<1<<1;
					return 0;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
			if(s1[3]=='F'){
				if(s2[3]=='D'){
					cout<<1<<1;
					return 0;
				}
				else{
					cout<<0<<0;
					return 0;
				}
			}
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
	}//³µÏá 
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
