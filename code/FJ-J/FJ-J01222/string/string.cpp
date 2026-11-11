#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,s[20005];
char z[20005];
vector<char> v;//bao li dai ma
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>z[i];
		while(s[i]--) v.push_back(z[i]);
	}
	long long mid=v.size();
	long long l=mid/2,r=mid/2+1;
	if(mid%2) r++;
	while(l>=1){
		if(v[l-1]!=v[r-1]) ans++;
		l--,r++;
	}
	cout<<ans;
//	cout<<mid<<" "<<l<<" "<<r;
return 0;}