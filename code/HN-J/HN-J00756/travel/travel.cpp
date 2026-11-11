#include<bits/stdc++.h> 
using namespace std;
long long n,m;
string s,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>g;
	if(n==m){
		cout<<1;
		bool f=true;
		for(int i=0;i<s.size();i++){
			for(int j=0;j<g.size();j++){
				if(s[0]==g[0]&&s[1]==g[1]){
					f=true;
				}else{
					f=false;
				}
				int a=s[2]-'0',b=g[2]-'0';
			}
		}
		if(f){
			cout<<1;
			bool d=true,k=true;
			for(int i=0;i<s.size();i++){
				for(int j=0;j<g.size();j++){
					if(s[2]<='C'&&g[2]<='C'){
						d=true;
						if(s[2]-'0'-(g[2]-'0')==1) {
							k=true;	
						}else{
							k=false;
						}
					}else if(s[2]>='D'&&g[2]>='D'){
						d=true;
							if(s[2]-'0'-(g[2]-'0')==1) {
							k=true;	
						}else{
							k=false;
						}
					}else{
						d=false;
					}
					
				}
			}
			if(d){
				cout<<1;
				if(k){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
