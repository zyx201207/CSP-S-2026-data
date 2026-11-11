#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,x;
	string s,c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]&&i<s.size()-i-1){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
