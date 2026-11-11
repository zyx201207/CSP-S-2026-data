#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k,cnt=0;
	cin>>n;
	string a,s;
	while(n--){
		cin>>k>>a;
		while(k--){
			s+=a;
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<s.size()/2;i++){
		cnt+=s[i]!=s[s.size()-i-1];
		//cout<<s[i]<<" "<<s[s.size()-i-1]<<endl;
	}
	cout<<cnt;
	return 0;
}
