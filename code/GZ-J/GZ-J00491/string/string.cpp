//GZ-J00491 遵义市第十九中学 陈昱昊 
#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++){
		long long x;
		char y;
		cin>>x;
		cin>>y;
		for(int j = 0;j<x;j++){
			s+=y;
		}
	}
	if(s.size() == 1){
		cout<<s[0];
		return 0;
	}
	int mid = s.size()/2;
	
	long long max1 = 0,max2 = 0;
	string s1,s2;
	for(int i = 0;i<mid;i++){
		s1+=s[i];
	}

	for(int i = s.size()-1;i>=s.size()-mid;i--){
		if(s[i]!=s1[s.size()-i-1]){
			max1++;
		}
	}
	for(int i = s.size()-1;i>=s.size()-mid;i--){
		s2+=s[i];
	}
	for(int i = 0;i<mid;i++){
		if(s[i]!=s2[i]){
			max2++;
		}
	}
	
	cout<<min(max1,max2);
}

