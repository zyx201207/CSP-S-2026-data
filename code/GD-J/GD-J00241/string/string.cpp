#include<bits/stdc++.h>
using namespace std;
//bool hwc(string s){
//	string rs = s;
//	reverse(rs.begin(),rs.end());
//	return rs==s;
//}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ssum = 0;
	cin >> n;
	string inps = "";
	for(int i = 1;i<=n;i++){
		int a;
		char c;
		cin >> a >> c;
		for(int j = 1;j<=a;j++){
			inps+=c;
		}
		ssum+=a;
	}
	long long ans=0;
	for(long long i = 0;i<(ssum/2);i++){
		if(inps[i]!=inps[ssum-1-i]){
			ans++;
		}
	}
	cout << ans;
}
