#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	vector <char> A;
	vector <char> B;
	for(long long i=1;i<=n;i++){
		long long b;
		char a;
		cin>>b>>a;
		for(long long j=1;j<=b;j++){
			A.push_back(a);
		}
	}
	for(long long i=A.size()-1;i>=0;i--){
		B.push_back(A[i]);
	}
	long long ans=0;
	for(long long i=0;i<A.size()/2;i++){
		if(A[i]!=B[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
