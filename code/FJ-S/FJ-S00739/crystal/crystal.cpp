#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long b[1000006];
long long a[1000006];
int main(){
	//记得取消注释和 in out文件 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long k=1000000;
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1]+a[i]; 
	}
	long long ma=0;
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=i;j++){
			if(a[i]*(i-j)-b[i]+b[j]<=m){
				ma=max(ma,i-j);
			}
		}
	}
	cout << ma;
	return 0;
}  
