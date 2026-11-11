#include<bits/stdc++.h>
using namespace std;

int c,t;
vector<long long> a;
vector<long long> reach;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int m = 1;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(a[i] - a[i-1] > d){
				m++;
				reach[i] = m;
			}
		}
		int ans=0;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				long long num = a[j] - a[i];
				if( ((num + 1) % d == 0 && num > d) && (reach[i] == reach[j])){
					//cout<<a[i]<<" "<<a[j]<<" ";
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
