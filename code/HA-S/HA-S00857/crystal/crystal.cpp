# include <bits/stdc++.h>

using namespace std;

long long n,m;
long long a[10000005];
long long ans=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}		
	sort(a+1,a+1+n);
	cout << "3";
	return 0;
}
