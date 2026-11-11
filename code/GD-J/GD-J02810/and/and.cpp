#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long b){
	return x>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	long long a[n+5]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	cout<<a[m-1];
	return 0;
} 
