#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int x=0;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		sum+=b;
		for(int j=x;j<sum;j++){
			s[j]=c;
			x=sum;
		}
	}
	int l=0,r=sum-1,ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			ans+=1;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
