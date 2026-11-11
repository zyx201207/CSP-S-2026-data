#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum1=0;
	cin >>n;
	for(int i=1;i<=n;i++){
		int t;
		char c;
		cin >>t>>c;
		sum1+=t;
		string s1;
		for(int i=1;i<=t;i++){
			s1=s1+c;
		}
	}
	string s2;
	int cnt=0;
	for(int i=1;i<=sum1;i++){
		s2=s2+s1[n-1];
	}
	for(int i=0;i<sum1;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout <<cnt/2;
	return 0;
}