#include<bits/stdc++.h> 
using namespace std;
string ss(string x){
	int j=x.size()-1;
	for(int i=0;i<j;i++){
		swap(x[i],x[j]);
		j--;
	}
	return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		long long a;
		char t;
		cin>>a>>t;
		for(int j=0;j<a;j++){
			s+=t;
		}
	}
	string w=s;
	if(s==ss(w)) {
		cout<<0;
		return 0;
	}
	int j=0;
	int c=0;
	for(int i=s.size()-1;i>=j;i--){
		string w=s;
		if(s==ss(w)){
			cout<<c;
			return 0;
		}
		if(s[i]!=s[j]){
			s[i]=s[j];
			c++;
		}
		j++;
	}
	return 0;
}
