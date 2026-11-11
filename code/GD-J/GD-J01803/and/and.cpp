#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
string s;
int a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
