#include <bits/stdc++.h>
using namespace std;
vector<char> arr;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	long long a;
	char c;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			arr.push_back(c);
		}
	}
	long long cnt=0;
	for(long long i=0;i<=arr.size()/2;i++){
		if(arr[i]!=arr[n-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}



