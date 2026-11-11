#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string tt(long long n){
	string ans;
	while(n){
		char a=n%2+48;
		ans+=a;
		n/=2;
	}
	return ans;
}
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=tt(a[i]);
	}
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			if(s[i]<s[j]) maxn=max(maxn,min(a[i],a[j]));
		}
	}
	cout<<maxn<<endl;
	return 0;
}
