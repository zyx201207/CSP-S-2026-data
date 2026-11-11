#include<bits/stdc++.h> 
using namespace std;

long long n,m;
long long a[300005],s[300005];

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	s[1]=a[1];
	for(int i=2;i<=m;i++){
		s[i]=a[i]&s[i-1];
	}
	cout << s[m];
	return 0;
}
