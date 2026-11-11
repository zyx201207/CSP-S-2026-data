#include<bits/stdc++.h>
using namespace std;
string s;
void pj(int i,char z){
	for(int j=0;j<i;j++){
		s+=z;
	}
}
int n,cnt;
long long ans=0;
char c;
void f1(){
	if(s.length()%2==0){
		int l=s.length()/2;
		for(int i=0,j=l*2+1;i<=l,j>l;i++,j--){
			if(s[i]!=s[j]) ans++; 
		}
	}else{
		int l=s.length()/2;
		for(int i=0,j=l*2;i<l,j>l;i++,j--){
			if(s[i]!=s[j]) ans++; 
		}
	}
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cnt>>c;
		pj(cnt,c);
	}
	f1();
	cout<<ans;
	return 0;
}
