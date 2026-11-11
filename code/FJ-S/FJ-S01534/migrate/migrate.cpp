#include<bits/stdc++.h>
using namespace std;
bool f[2000005][2000005];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n;
		long long d;
		long long x[2000005];
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

//N is "and" of "n" of each number of one point
 //0 <= c <= 25   2 <= t <= 10^5
 // 1 <= n <= 2 * 10^6   N <= 2 * 10^6   1 <= d <= 2 * 10^18
 //  -10^18 <= x 1 < x 2 < ... < x n <= 10^18