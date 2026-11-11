#include <bits\stdc++.h>
using namespace std;

long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//图论+贪心+新定义 
	long long c,t;
	cin >> c >> t;
	for(long long i=1;i<=t;i++){
		long long n,d,sum=0;
		cin >> n >> d;
		for(long long j=1;j<=n;j++){
			cin >> a[j];
			sum+=a[j];
		}
		if(sum%2==0){
			cout << 0 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}
	return 0;
}
