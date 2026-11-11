#include<bits/stdc++.h>
using namespace std;
long long n;
long long m[10001];
string p,s;
long long len;
long long pan_duan(int len,string s){
	for(int i=len;i>len/2;i--){
		for(int j=0;j<len/2;j++){
			if(s[i]==s[j]){
				return true;
			}else{
				return false;
			}
		}
	}
	
}
long long pin_jie(int len,string s){
	long long count=0; 
	for(int i=len;i>len/2;i--){
		for(int j=0;j<len/2;j++){
			if(s[i]!=s[j]){
				s[i]=s[j];
				i--;
				j++;
				count+=1;
			}
			if(pan_duan(len,s)==true){
				cout<<count;
			}
		}
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i]>>p[i];
		while(m[i]--){
			s[i]+=p[i];
		}
		if(p[i]=='a'){
			cout<<"0";
		}else{
			cout<<"2";
		}
	}
	len=s.length();
	pin_jie(len,s);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
