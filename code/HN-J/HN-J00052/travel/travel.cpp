#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	string s,s1;
	cin>>n>>s>>m>>s1;
	if(n==m){
		cout<<1;
		int e=(s[0]-'0')*10+(s[1]-'0');
		int o=(s1[0]-'0')*10+(s1[1]-'0');
		if(e==o){
			cout<<1;
			e=s[2]-'A';
			o=s1[2]-'A';
			if((e==0||e==1||e==2)&&(o==0||o==1||o==2)){
				cout<<1;
				if(abs(e-o)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((e==3||e==4)&&(o==3||o==4)){
				cout<<1;
				if(abs(e-o)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
} 
