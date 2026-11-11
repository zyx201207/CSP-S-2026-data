#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	long long x;
	char a;
	while(n--){
		cin>>x>>a;
		while(x--){
			s+=a;
		}
	}
	long long sum=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])sum++;
	}
	cout<<sum;
	return 0;
}
