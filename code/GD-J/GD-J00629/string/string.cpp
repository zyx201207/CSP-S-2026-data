#include<bits/stdc++.h>
using namespace std;

int n;
long long sum=0;
string s;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		long long m;
		char c;
		cin>>m>>c;
		for(int j=0;j<m;j++){
			s+=c;
		}
	}
	
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			sum++;
		}
	}
	
	cout<<sum;
	return 0;
}
