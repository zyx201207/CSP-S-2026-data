#include<bits/stdc++.h>
using namespace std;
const int MAX = 50010;
long long m,n,B[MAX];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>B[i];
	}
	sort(B+1,B+n+1,cmp);
	long long ans = 1;
	for(int i = 1;i <= n;i++){
		int p = 1;
		long long sum = 0;
		long long reans = 0;
		long long C[MAX] = {0};
		for(int j = 1;j <= n;j++){
			C[j] = B[j]-B[i];
		}
		while(m + sum>= 0&&p <= n){
			if(C[p] <= 0){
				sum+=C[p];
				if(sum + m<0) break;
				reans++;
			}
			p++;
		}
		ans = max(reans,ans);
	}
	cout<<ans;
	return 0;
}