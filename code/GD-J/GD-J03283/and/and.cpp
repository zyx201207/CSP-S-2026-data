#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long answ = 0;
	const int maxn = 2e5+5; 
	long long a[maxn];
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n-m+1;i++){
		long long c = a[i];
		for(int j = i+1;j <= i+m;j++){
			c = c&a[j];
		}
		answ = max(answ,c);
	}
	cout<<answ;
	return 0;
}
