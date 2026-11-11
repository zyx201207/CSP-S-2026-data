#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		char c;
		cin>>c;
		while(x--){
			s=s+c;
		}
	}
	if(s.size()%2==1){
		n=s.size()/2+1;
	}
	else{
		n=s.size()/2;
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
