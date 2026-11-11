#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,m,a[2000005],l,maxn,T,_;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_>>T;
	while(T--){
		l=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i+3<=n;i++){
			if(a[i]+m>=a[i+2]&&a[i]+m>=a[i+1]&&a[i+1]+m>=a[i+2]&&a[i+2]+m>=a[i+3]&&a[i+1]+m>=a[i+3]&&a[i]+m<a[i+3]){
				l++;
				int k=i+4;
				while(k<=n&&k%2==0){
					if(a[k-1]+m>=a[k]){
						l++;
					}else{
						break;
					}
					k++;
				}
			}
		}
		cout<<l<<'\n';
	}
}
