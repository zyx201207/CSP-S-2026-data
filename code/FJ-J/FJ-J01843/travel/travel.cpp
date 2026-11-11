#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int s3=s1[2],s4=s2[2];
	if(c1==c2){
		cout<<1;
	}else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		}else {
			cout<<0<<0<<0;
			return 0;
		}
		if(s3>=65&&s3<=67){
			if(s4>=65&&s4<=67){
				cout<<1;
			}else{
				cout<<0<<0;
				return 0;
			}
		}else if(s4>='D'&&s4<='F'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
		if(s3=='D'){
			if(s3+1==s4){
				cout<<1;
			}else cout<<0;
		}else if(s3=='F'){
			if(s3-1==s4){
				cout<<1;
			}else cout<<0;
		}
		if(s3=='B'){
			if(s3-1==s4||s3+1==s4){
				cout<<1;
			}else cout<<0;
		}else if(s3=='C'){
			if(s3-1==s4){
				cout<<1;
			}else cout<<0;
		}else if(s3=='A'){
			if(s3+1==s4){
				cout<<1;
			}else cout<<0;
		}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
