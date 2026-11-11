#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long a;
	char b,c;
	string s;
	bool flag=true;
	cin>>a>>b;
	c=b;
	for(long long j=0;j<a;j++){
		s+=b;
	}
	for(long long i=1;i<n;i++){
		cin>>a>>b;
		for(long long j=0;j<a;j++){
			s+=b;
		}
		if(c!=b){
			flag=false;
		}
	}
	if(flag){
		cout<<0<<endl;
		return 0;
	}
	long long num=0;
	if(s.length()%2==0){
		num=s.length()/2;
	}
	else{
		num=s.length()/2+1;
	}
	string x,y;
	for(long long i=0;i<num;i++){
		x+=s[i];
	}
	for(long long i=num-1;i>=0;i--){
		y+=x[i];
	}
	x+=y;
	for(long long i=0;i<x.length();i++){
		if(x[i]!=s[i]){
			ans+=1;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
