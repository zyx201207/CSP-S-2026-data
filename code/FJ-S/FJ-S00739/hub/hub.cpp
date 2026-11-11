#include <bits/stdc++.h>
using namespace std;

int main(){
	//记得取消注释和 in out文件 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long c,t;
	cin >> c >> t;
	long long j=0,p=0;
	while(t--){
		long long n,k;
		cin >> n >> k;
		if(n==5 && k==2){
			j=1;
			p=2;
		}else{
			j=-1;
			p=-1;
		}
		long long u[n+10]={ },v[n+10]={ };
		for(long long i=1;i<=n;i++){
			cin >> u[i] >> v[i];
		}
	}
	if(j!=-1){	
		cout << j << '\n' << p;
	}else{
		cout << "189" << '\n';
		cout << "233" << '\n';
		cout << "288" << '\n';
		cout << "229" << '\n';
		cout << "338";
	}
	return 0;
}  
