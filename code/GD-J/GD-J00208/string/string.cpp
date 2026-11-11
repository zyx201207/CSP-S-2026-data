#include <bits/stdc++.h>
using namespace std;

string s;
char a;
int n,m;
bool check(long long mid){
	long long cnt=0,L=s.size();
	for(int i=0;i<L/2;i++){
		if(s[i]!=s[L+1-i]){
			cnt++;
		}
		if(cnt>mid) return false;
	}
	return true;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> m >> a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	if(n==1){
		cout << 0;
		return 0;
	}
	long long r=0,l=s.size()+1,ans=0;
	while(l>=r){
		long long mid=l+(r - l)/2;
		if(check(mid)){
			l=mid-1;
			ans=mid;
		}
		else{
			r=mid+1;
		}
	}
	cout << ans;
	
	return 0;
}
