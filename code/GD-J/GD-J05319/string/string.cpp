#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	string s,s1;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		int k;
		string c;
		cin>>k>>c;
		for(long long j=0;j<k;j++){
			s=s+c;
		}
//		cout<<s<<" ";
		s1=s;
		reverse(s.begin(),s.end());
		for(long long j=1;j<s1.size()/2;j++){
			if(s1[j]!=s[j]){
				ans++;
			}
		}
	}
//	cout<<s1<<" "<<s<<" ";
	cout<<ans;
	return 0;
}
