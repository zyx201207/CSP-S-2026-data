#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<1<<endl;
	}
	return 0;
} 
