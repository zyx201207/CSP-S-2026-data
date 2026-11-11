#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		int q;
		char p;
		cin>>q>>p;
		for(int i=0;i<q;i++){  
			s+=p;
		}
	}	
	long long l=0;
	long long r=s.size()-1;
	while(1){
		if(r<=l) break;
		if(s[l]!=s[r]){
			sum++;
		}
		r--;
		l++;
	}
	cout<<sum;
	return 0;
}
