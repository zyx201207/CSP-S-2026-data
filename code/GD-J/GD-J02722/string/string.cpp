#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	cin>>n;
	string s,x,b;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for (int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i=0;i<s.length();i++){
		x[i]=s[s.length()-1-i];
	}
	for(int i=0;i<s.length();i++){
		if(x[i]!=s[i]){
			sum+=1;
		}
	}
	cout<<sum/2;
	return 0;
}
