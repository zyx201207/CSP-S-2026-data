#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,cnt;
long long ans;
struct node{
	long long k;
	char c;
}a[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
		for(int j=1;j<=a[i].k;j++){
			s+=a[i].c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

