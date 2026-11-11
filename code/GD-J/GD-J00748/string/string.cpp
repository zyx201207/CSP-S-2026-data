#include<bits/stdc++.h>
using namespace std;
vector<char>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		scanf("%lld %c",&a,&c);
		for(int j=1;j<=a;j++){
			s.push_back(c);
			len++;
		}
	}
	long long ans=0;
	long long l=0,r=len-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
