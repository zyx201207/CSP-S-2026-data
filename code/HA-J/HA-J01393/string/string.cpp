#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	if(n==1){cout<<0;return 0;
	}
	int a[n+2];string s;
	char b[n+2];
	for(int i=0;i<n;++i){
	cin>>a[i];cin>>b[i];
    s+=b[i];
	}
	int l=0,r=s.size()-1;
	long long ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
		ans+=max(a[l],a[r]);}
		l++;
		r--;
	}
	cout<<ans;
}
