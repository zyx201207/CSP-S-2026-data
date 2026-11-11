#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
string c,C;
map<char,long long> mp;
int ddd(){
	int d=0;
	for(int i=1;i<=n;i++){
		mp[C[i]]+=a[i];
	}
	for(char i='a';i<='z';i++){
		d+=mp[i]%2;
	}
	return d;
}
int bbb(long long ans){
	for(int i=1;i<=n;i++){
		mp[C[i]]+=a[i];
	}
	int maxn=0;
	for(char i='a';i<='z';i++){
		if(mp[i]>maxn){
			maxn=mp[i];
		}
	}
	return ans-maxn;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		C+=c;
	}
	if(n==2){
		if(a[1]==a[2]){
			cout<<0;
			return 0;
		}
		cout<<min(a[1],a[2]);
		return 0;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	if(ans%2!=0){
		cout<<ddd();
	}else{
		cout<<bbb(ans);
	}
	return 0;
}
