#include <bits/stdc++.h>
using namespace std;
long long a[100001];
bool cmp(int x,int y){
	return x>y;
}
long long cnt; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","l",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cnt=a[0];
	for(int i=1;i<m;i++){
		cnt&=a[i];
	}
	cout<<cnt;
	return 0;
}
