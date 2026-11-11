#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long slen=0;
	while(n--){
		long long a;
		string b;
		cin>>a>>b;
		slen+=a;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
//	cout<<"s1="<<s<<endl;
//	cout<<"len="<<slen<<endl;
	long long ans=0;
	for(long long i=0;i<slen;i++){
		if(s[i]!=s[slen-1-i]){
//			cout<<"i="<<i<<endl;
//			cout<<"s[i]="<<s[i]<<" ";
//			cout<<"s[len-i]="<<s[slen-1-i]<<endl;
			s[slen-1-i]=s[i];
//			cout<<"s[i]="<<s[i]<<" ";
//			cout<<"s[len-i]="<<s[slen-1-i]<<endl;
			ans++;
		}
	}
//	cout<<"s2="<<s<<endl;
	cout<<ans;
	return 0;
}
