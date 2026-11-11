#include<bits/stdc++.h>
using namespace std;
#define long long int
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int cnt = 0,num = 0;
	char s3,s4;
	cin>>c1>>s1>>c2>>s2;
	
	
	
	if(c1 == c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	
	for(int i = 0;i<s1.size();i++){
		if(isdigit(s1[i])){
			cnt+=s1[i]-'0';
		}
		if(isdigit(s2[i])){
			num+=s2[i]-'0';
		}
		if(isupper(s1[i])){
			s3=s1[i];
		}
		if(isupper(s2[i])){
			s4=s2[i];
		}
	}
	
	
	if(cnt == num){
		cout<<1;
		if((s4>='A' && s4<='C') && (s3>='A' && s3<='C')){
			cout<<1;
		}else if((s4>='D' && s4<='F') && (s3>='D' && s3<='F')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else{
		cout<<0<<0;
	}
	
	
	if((s4>='A' && s4<='C') && (s3>='A' && s3<='C')){
		if(num == cnt && (s3-s4 == -1 || s3-s4 == 1)){
			cout<<1;
		}else if(s3 == s4 && num-cnt<=1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if((s4>='D' && s4<='F') && (s3>='D' && s3<='F')){
		if(num == cnt){
			cout<<1;
		}else if(s3 == s4 && num-cnt<=1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}
