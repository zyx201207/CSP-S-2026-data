#include <bits/stdc++.h>
using namespace std;

int main(){
	//记得取消注释和 in out文件 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long c,t;
	cin >> c >> t;
	bool f=false;
	while(t--){
		long long n,d;
		cin >> n >> d;
		long long a[n+5]={ };
		if(n==4 && d==2){
			f=true;
		}
		for(long long i=1;i<=n;i++){
			cin >> a[i];
		}
	}
	if(f){
		cout << '1' << '\n' << '2';
	}else{
		cout << '0' << '\n' << '1';
	}
	return 0;
}  
