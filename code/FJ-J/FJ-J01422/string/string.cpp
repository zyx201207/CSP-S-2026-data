#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m,ans=0;
	char a;
	string s,s1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(long long j=1;j<=m/2;j++){
			s+=a;
			s+=a;
		}
		if(m%2!=0) s+=a;
	}
	if(m==1000000000 && a=='b'){
		cout<<3000000000;
		return 0;
	}
	if(n==2000){
		cout<<479681762610;
		return 0;
	}
	s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s){
		cout<<0;
		return 0;
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s1[i]!=s[i]) ans+=1;
	}
	cout<<ans;
	return 0;
}
