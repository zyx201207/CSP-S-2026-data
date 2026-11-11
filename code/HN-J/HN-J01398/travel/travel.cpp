#include<bits/stdc++.h>
using namespace std;
typedef long long LL; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,x1,x2;
	cin>>s1>>s2>>x1>>x2;
	bool f=false;
	if(s1!=x1)cout<<0;
	else cout<<1;
	if(s2[0]==x2[0]&&s2[1]==x2[1]&&s1==x1)cout<<1;
	else cout<<0;
	if(s2[0]==x2[0]&&s2[1]==x2[1]&&s1==x1){
		if(s2[2]=='A'){
			if(x2[2]=='B'||x2[2]=='C'){
				f=true;
				cout<<1;
			}
			else cout<<0;
		}
		if(s2[2]=='B'){
			if(x2[2]=='A'||x2[2]=='C'){
				f=true;
				cout<<1;
			}
			else cout<<0;
		}
		if(s2[2]=='C'){
			if(x2[2]=='B'||x2[2]=='A'){
				f=true;
				cout<<1;
			}
			else cout<<0;
		}
		if(s2[2]=='D'){
			if(x2[2]=='F'){
				f=true;
				cout<<1;
			}
			else cout<<0;
		}
		if(s2[2]=='F'){
			if(x2[2]=='D'){
				f=true;
				cout<<1;
			}
			else cout<<0;
		}
	}else cout<<0;
	if(f){
		if(abs(int(s2[2]-x2[2]))==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else cout<<0;
	
	return 0;
}

