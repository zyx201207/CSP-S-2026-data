#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	long long n,a,num=0;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]){
			num+=0;
		}
		else{
			num+=1;
		}
	}
	cout<<num;
	return 0;
} 

