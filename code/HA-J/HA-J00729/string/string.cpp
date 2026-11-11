#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long a;
	char c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long cnt=0;
	for(long long i=0;i<s.size()/2;i++){
		long long j=s.size()-1;
		if(s[i]!=s[j]){
			cnt++;
	    } 
		j--;
	}
	cout<<cnt;
	return 0;
}
