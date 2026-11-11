#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
			cout<<1;
			if(((char)(s1[2])<='A' && ((char)(s1[2])>='C') && ((char)(s2[2])<='A' && (char)(s2[2])>='C')) || (((char)(s1[2])<='D' && (char)(s1[2])>='F') && ((char)(s2[2])<='D' && (char)(s2[2])>='F'))){
				cout<<1;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<0;
			if((((char)(s1[2])<='A' && (char)(s1[2])>='C') && ((char)(s2[2])<='A' && (char)(s2[2])>='C')) || (((char)(s1[2])<='D' && (char)(s1[2])>='F') && ((char)(s2[2])<='D' && (char)(s2[2])>='F'))){
				cout<<1;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}else{
		cout<<0;
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
			cout<<1;
			if((((char)(s1[2])<='A' && (char)(s1[2])>='C') && ((char)(s2[2])<='A' && (char)(s2[2])>='C')) || (((char)(s1[2])<='D' && (char)(s1[2])>='F') && ((char)(s2[2])<='D' && (char)(s2[2])>='F'))){
				cout<<1;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<0;
			if((((char)(s1[2])<='A' && (char)(s1[2])>='C') && ((char)(s2[2])<='A' && (char)(s2[2])>='C')) || (((char)(s1[2])<='D' && (char)(s1[2])>='F') && ((char)(s2[2])<='D' && (char)(s2[2])>='F'))){
				cout<<1;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				if(s1[2]-1==s2[2] ||s1[2]+1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
