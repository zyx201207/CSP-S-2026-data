#include <bits/stdc++.h>;
using namespace std;
int main(){
	//forpoen(string.in,"r",stdin);
	//forpoen(string.out,"w",stdout);
	
	string n;
	cin>>n;
	s[n]=0;
	cin<<s[n]endl;
	for(int i=0;i<=s[n];i++){
		s[n]+=s[n+i];
		if(s[n]=s[n-1]){
			cout<<s[n];
		}
	}
	return 0;
}
