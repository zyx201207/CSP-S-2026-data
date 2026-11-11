#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	char s5,s6;
	long long n=0,m=0,a=0,b=0;
	for(long long i=0;i<3;i++){
		if(i==0){
			n+=(s1[i]-48)*10;
			m+=(s3[i]-48)*10;
			a+=(s2[i]-48)*10;
			b+=(s4[i]-48)*10;
		}else if(i==1){
			n+=s1[i]-48;
			m+=s3[i]-48;
			a+=s2[i]-48;
			b+=s4[i]-48;
		}else{
			s5=s2[i];
			s6=s4[i];
		}
	}
	if(n==m){
		cout<<1;
		if(a==b) {
			cout<<1;
			if(s5=='A'||s5=='B'||s5=='C'){
				if(s6=='A'||s6=='B'||s6=='C') {
					cout<<1;
					if(s6==s5+1||s6==s5-1) cout<<1;
					else cout<<0;
				}
				else{
					cout<<0<<0;	
				} 
			}else{
				if(s6=='D'||s6=='F'){
					cout<<1;
					if(s6==s5+1||s6==s5-1) cout<<1;
					else cout<<0;
				}
				else{
					cout<<0<<0;
				} 
			}
		}
		else{
			cout<<0<<0<<0;
		} 
		
	} 
	else{
		cout<<0<<0<<0<<0;
	} 
	return 0;
}
