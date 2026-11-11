#include<bits/stdc++.h>
using namespace std;
long long n;
long long x,sum,ans;
string s,s1,ss1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		for(long long j=1;j<=x;j++){
			s1+=s;
			ss1=s+ss1;
		}
		sum+=x;
	}
	if(s1==ss1){
		cout<<0;
		return 0;
	}
	for(long long j=0;j<sum/2;j++){
		if(s1[j]!=ss1[j]) ans++;
	}
	cout<<ans;
	return 0;
}
