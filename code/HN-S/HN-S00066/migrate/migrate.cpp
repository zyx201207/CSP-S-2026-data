#include<bits/stdc++.h>
using namespace std;
long long pos[2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t){
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>pos[i];
		}
		if(n==1){
			cout<<0<<endl;
			t--;
			continue;
		}
		long long delta=pos[1]-pos[0];
		if(d<2*delta){
			cout<<0<<endl;
			t--;
			continue;
		}
		cout<<n-3<<endl;
		t--;
	} 
	return 0;
} 
