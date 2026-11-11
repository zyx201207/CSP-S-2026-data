#include<bits/stdc++.h>
using namespace std;
int cheak(string s){
	int n=s.size(),i=0,j=s.size()-1,cnt=0;
	while(n>1){
		n-=2;
		if(s[i]!=s[j]){
			cnt++;
		}
		i++;
		j--;
	}
	return cnt;
}	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	cout<<cheak(s);
	return 0;
}
