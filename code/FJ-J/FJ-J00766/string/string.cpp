#include<bits/stdc++.h>
using namespace std;
long long ans;
/*bool is_hw(string s,int l,int r){
	while(r>l){
		if(s[l]==s[r]){
			r--;
			l++;
		}
		else return 0;
	}
	return 1;
}*/

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int j=1;j<=num;j++){
			s+=c;
		}
	}

	
	int l=0,r=s.size()-1;
	
	
	/*if(is_hw(s,l,r)) {
		cout<<0;return 0;
	}*/
	
	
	while(r>l){
		if(s[l]!=s[r]){
			ans++; 
		}
		r--;
		l++;
	}
	cout<<ans; 
	return 0;
}
