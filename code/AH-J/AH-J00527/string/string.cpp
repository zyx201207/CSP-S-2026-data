#include<bits/stdc++.h>
using namespace std;
string a,s1,s2;
long long n,i,j,t[100005],val,ans;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>t[i]>>c[i];
	}
	long long u=t[1];
	for(i=2;i<=n;i++){
		u=__gcd(u,t[i]);
	}
	for(i=1;i<=n;i++){
		t[i]/=u;
		while(t[i]--){
			a+=c[i];
		}
	}
	if(a.size()%2!=0){
		s1=a.substr(0,a.size()/2+1);
		s2=a.substr(a.size()/2,a.size()-1);
	}
	else{
		s1=a.substr(0,a.size()/2);
		s2=a.substr(a.size()/2,a.size()-1);
		
	}
	for(i=0;i<s1.size();i++){
		if(s1[i]!=s2[s1.size()-i-1]) ans++;
	}
	cout<<ans*u;
	return 0;
}
