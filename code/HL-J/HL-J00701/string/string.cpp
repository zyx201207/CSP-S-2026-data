#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("shs.in","r",stdin);
	freopen("shs.out","w",stdout);
	
	long long n,sum=0; cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long long1;
		char j;
		cin>>long1>>j;
		 while(long1){
		 	s+=j;
		 	long1--;
		 }
	}
	long long a=s.size()+1;
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[a--])
		sum++;
	}
	cout<<sum;
	return 0;
}