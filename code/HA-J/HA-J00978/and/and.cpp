#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=35;
int b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	if(m==n){
		long long ans=b[1];
		for(int i=2;i<=n;i++){
			ans=ans&b[i];
		}
		cout << ans;
		return 0;
	}
	if(m==1){
		sort(b+1,b+1+n);
		cout << b[n];
		return 0;
	}
	if(m==2){
		long long ans=0;
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,b[i]%b[j]);
			}
		}
		cout << ans;return 0;
	}
	
}
