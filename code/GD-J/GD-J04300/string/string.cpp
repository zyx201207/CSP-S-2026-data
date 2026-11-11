#include <bits/stdc++.h>
using namespace std;
char S[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long cnt=0;
	int l=1;
	int n;cin>>n;
	for (int i=1;i<=n;i++){
		long long a;char b;
		cin>>a>>b;
		for (int j=1;j<=a;j++){
			S[l]=b;l+=1;
		}
	}
	for (int i=1,j=l-1;i<j;i++,j--){
		if (S[i]!=S[j])  cnt+=1;
	}
	cout<<cnt;
	return 0;
}
