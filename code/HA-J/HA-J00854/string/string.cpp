#include<bits/stdc++.h>
using namespace std;
	long long a[200000];
	char c[200000];
	string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out"."w",stdout);
	long long n,sum=0,ca=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		ca+=c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(char i='a';i<='z';i++){
		string b;
		for(int j=0;j<ca;j++){
			b+=i;
		}
		if(s==b){
			i='z'+1;
			ca=-1;
	}
}
	for(int i=0;i<(s.size()+1)/2;i++){
		if(ca==-1){
			break;
		}else{
		if(s[i]==s[s.size()-i]){
			
		}else{
			sum++;
		}
	}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
