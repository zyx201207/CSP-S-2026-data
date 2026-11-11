#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
using namespace std;
const int N=2e6+5;
const int INF=-1e9;

int n,d;
int a[N];

bool arr2(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			return false;
		}
	}
	return true;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; 
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(arr2()){
			if(d<a[2]-a[1]){
				cout<<0<<endl;
				continue;
			}
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=min((i-1),(n-i));
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
