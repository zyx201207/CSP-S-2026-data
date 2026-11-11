#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	string s1,s2;
	int idx = 0;
	int sum = 0;
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		char c;cin >> c;
		sum+=x;
		for(int j=1;j<=x;j++){
			s1[idx] = c;
			s2[idx] = c;
			idx++;
		}
	}
	int cnt = 0;
	for(int i=0;i<=sum-1;i++){
		for(int j=sum-1;j>=0;j--){
			if(s1[i]!=s2[sum-i]) cnt++;
			break;
		}
	}
	cout << cnt/2;
	return 0;
}

