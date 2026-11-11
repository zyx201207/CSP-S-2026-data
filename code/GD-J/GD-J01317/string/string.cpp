#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	int a;
	cin>>a;
	int n[a];
	char c[a];
	for(int i=0;i<a;i++){
		cin>>n[i]>>c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<n[i];j++){
			s+=c[i]; 
		}
	}
	int ans=0;
	int i=0;
	int j=s.length()-1;
	while(i<j){
		if(s[i]!=s[j])ans++;
		i++;
		j--; 
	}
	cout<<ans;
	return 0; 
}
