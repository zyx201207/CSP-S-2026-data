#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	string s="";
	while(n--){
		long long a;cin>>a;
		string b;cin>>b;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	string ss="";
	for(int i=s.size()-1;i>=0;i--){
		ss+=s[i];
	}
	long long sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=ss[i]){
			sum++;
		}
	}
	cout<<sum/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
