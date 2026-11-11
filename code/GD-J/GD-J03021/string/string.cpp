#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cnt=0;
	string q,s;
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>q;
		for(long long i=1;i<=a;i++)
			s+=q;
	}
	//cout<<s<<endl;
	long long l=0,r=s.size()-1;
	//cout<<l<<" "<<r<<endl;
	while(r>=l){
		if(s[l]!=s[r]){
			cnt++;
		}
		r--;
		l++;
	}
	cout<<cnt;
	return 0;
} 
