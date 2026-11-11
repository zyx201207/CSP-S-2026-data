#include<bits/stdc++.h>
using namespace std;
string s;
void add(int a,string b){
	while(a--){
		s+=b;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int a;
		string b;
		cin>>a>>b;
		add(a,b);
	}
	string s1,s2;
	for(long long i=0;i<s.size()/2;i++){
		s1+=s[i]; 
		s2+=s[s.size()-1-i];
	}
	long long sum=0;
	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
