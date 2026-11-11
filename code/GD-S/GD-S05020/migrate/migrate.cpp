#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l = 1,r = n;
		while(l<=r){
			int mid = (l+r)/2;
			if(check(mid)){
				l=mid;
			}else{
				r=mid;
			}
		}
	}
}
