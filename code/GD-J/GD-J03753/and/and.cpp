#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
long long a[N];
long long zero = 0; 
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) zero++;
	}
	if(zero>=n-m) {
		cout<<'0'<<endl;
		return;
	}
	
	if(m==2&&n<=5000){
		long long maxst = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				long long tmp = a[i]&a[j];
				maxst = max(maxst,tmp);
			}
		}
		cout<<maxst<<endl;
		return;
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1]<<endl;
		return;
	} 
	long long st = a[1];
	for(int i = 1;i<=m;i++){
		st&=a[i];
	}
	cout<<st<<endl;
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
