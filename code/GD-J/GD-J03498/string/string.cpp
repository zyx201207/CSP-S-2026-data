#include<bits/stdc++.h>
using namespace std;
const long long N=1e6;
long long ans=0,n,m,sum,t;
string s;
char c;
int main(){ 
	s+='0';
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		cin>>c;
		for(int i=1;i<=t;i++){
			s+=c;
		}
		sum+=t;
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
