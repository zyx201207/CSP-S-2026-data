#include <bits\stdc++.h>
using namespace std;

long long st[1000005];
long long fi[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//Ê÷+Ì°ÐÄ+??? 
	long long c,t;
	cin >> c >> t;
	for(long long i=1;i<=t;i++){
		long long n,k,sum;
		cin >> n >> k;
		for(long long j=1;j<n;j++){
			cin >> st[j] >> fi[j];
			sum+=st[j];
			sum+=fi[j];
		}
		if(sum%2==0)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}
