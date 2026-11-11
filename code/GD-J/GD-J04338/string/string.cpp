#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	s.clear();
	for(int i=0;i<n;i++){
		long long num;
		char ch;
		cin>>num>>ch;
		for(long long j=0;j<num;j++){
			s+=ch;
		}
	}
	long long lens=s.size();
	long long ans=0;
	if(lens%2==0){
		for(long long i=0;i<lens;i++){
			if(i>=lens-i-1){
				break;
			}
			if(s[i]!=s[lens-i-1]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}else{
		for(long long i=0;i<lens;i++){
			if(i==lens-i-1){
				break;
			}
			if(s[i]!=s[lens-i-1]){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
