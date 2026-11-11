#include<bits/stdc++.h>
using namespace std;
vector<char> a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char z;
		cin>>x>>z;
		for(long long j=1;j<=x;j++){
			a.push_back(z);
		}
	}
	for(long long i=a.size()-1;i>=0;i--){
		b.push_back(a[i]);
	}
	for(long long i=0;i<=a.size()-1;i++){
		if(a[i]!=b[i]){
			sum++;
		}
	}
	sum/=2;
	cout<<sum;
	return 0;
}
