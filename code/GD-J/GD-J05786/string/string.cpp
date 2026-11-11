#include<bits/stdc++.h> 
using namespace std;
int main(){
	long long int n,a,ans=0,k=0;
	string s;
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		k+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long int i=0;
	k--;
	while(i<k){
		if(s[i]!=s[k])ans++;
		i++;
		k--;
	}
	cout<<ans;
	return 0;
} 
