#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,f=0,ans=0;
	char c;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s+=c;
		}
	} 
	vector<long long> error(s.length());
	for(long long i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			error[f]=i;
			f++;
			
		}
	}
	if(f==0){
		cout<<'0';return 0;
	}
	cout<<f;
	return 0;
	
}
