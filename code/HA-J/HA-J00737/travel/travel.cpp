#include<bits/stdc++.h>
using namespace std;
long long x,y;
string s,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s>>y>>k;
	if(x!=y){
		cout<<"0000"<<endl;
		return 0;
	}else{
		int l=s[0]-'0',r=s[1]-'0',h=l*10+r,l1=k[0]-'0',r1=k[1]-'0',h1=l1*10+r1;
		if(h!=h1){
			
			cout<<"1000"<<endl;
			return 0;
		}else{
			char d=s[2],f=k[2];
			int ss=0,sd=0;
			if(d=='A'||d=='B'||d=='C'){
				ss=0;
			}else{
				ss=1;
			}
			if(f=='A'||f=='B'||f=='C'){
				sd=0; 
			}
			else{
				sd=1;
			}
			if(ss!=sd){
				cout<<"1100"<<endl;
				return 0;
			}else{
				if(sd==0){
					if(d=='A'){
						if(f!='B'){
							cout<<"1110"<<endl;
							return 0;
						}else{
							cout<<"1111"<<endl;
							return 0;
						}
					}
					if(d=='B'){
						if(f=='A'||f=='C'){
							cout<<"1111"<<endl;
							return 0;
						}
						else{
							cout<<"1110"<<endl;
							return 0;
						}
					}else if(d=='C'){
						if(f=='B'){
							cout<<"1111"<<endl;
							return 0;
						}else{
							cout<<"1110"<<endl;
							return 0;
						}
					}
					if(d=='F'){
						if(f=='D'){
							cout<<"1111"<<endl;
							return 0;
						}else{
							cout<<"1110"<<endl;
							return 0;
						}
					}
					else if(d=='D'){
						if(f=='F'){
							cout<<"1111"<<endl;
							return 0;
						}else{
							cout<<"1110"<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
} 

