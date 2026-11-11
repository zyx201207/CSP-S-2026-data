#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
bool hw(string s){
	string s1="";
	for(int i=s.size()-1;i>=0;i--){
		s1=s1+s[i];
	}
	return s==s1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	int si=s.size();
	if(si%2==0){
		string b1="";
		for(int i=0;i<=si/2-1;i++){
			b1=s[i]+b1;
		}
		int ans1=0;
		int j=0;
		for(int i=si/2;i<=si-1;i++){
			if(b1[j]!=s[i]){
				ans1++;
				j++;
			} 
		}
		string b2="";
		for(int i=si/2;i<=si-1;i++){
			b2=s[i]+b2;
		}
		int ans2=0;
		int j2=0;
		for(int i=0;i<=si/2-1;i++){
			if(b2[j2]!=s[i]){
				ans2++;
				j2++;
			} 
		}
		cout<<min(ans1,ans2);
	}
	else{
		string b1="";
		for(int i=0;i<=si/2-1;i++){
			b1=s[i]+b1;
		}
		int ans1=0;
		int j=0;
		for(int i=si/2+1;i<=si-1;i++){
			if(b1[j]!=s[i]){
				ans1++;
				j++;
			} 
		}
		string b2="";
		for(int i=si/2+1;i<=si-1;i++){
			b2=s[i]+b2;
		}
		int ans2=0;
		int j2=0;
		for(int i=0;i<=si/2-1;i++){
			if(b2[j2]!=s[i]){
				ans2++;
				j2++;
			} 
		}
		cout<<min(ans1,ans2);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
