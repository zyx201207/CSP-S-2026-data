#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		string c;
		cin>>c;
		for(long long j=a;j>0;j--){
			s+=c;
		}
	}
	
	
	for(long long i=0;i<=s.size();i++){
		if(s[i]==s[0]){
			cout<<0<<endl;
			return 0;
		}
	}
	long long l=0;
	long long r=s.size();
	long long ans=0;
	while(l>=r){
		if(s[l]!=s[r]){
			ans+=1;
			l+=1;
			r-=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
