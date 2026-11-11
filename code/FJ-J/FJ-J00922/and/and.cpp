#include<bits/stdc++.h>
using namespace std;

bool cmp(long long x,long long y){
	
	return x>y;
}

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	
	cin >> n >> m;
	vector<long long> a(n);
	
	for(int i=0;i<n;i++) cin >> a[i];
	
	sort(a.begin(),a.end(),cmp);
	long long x=a[0];
	
	for(int i=1;i<m;i++) x=x&a[i];
	
	cout << x;
	
	return 0;
}
