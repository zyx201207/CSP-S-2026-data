#include<bits/stdc++.h>
using namespace std;
long long x[2000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<4){
			cout<<0<<"\n";
			continue;
		}
		if(c==11||c==12){
			long long cnt=x[2]-x[1];
			cnt=d/cnt;
			if(d<=cnt||cnt<2){
				cout<<0<<"\n";
				continue;
			}
			if(n>=cnt*2){
				cout<<n-cnt*2+1<<"\n";
			}
			else cout<<0<<"\n";
			continue;
		}
	}
	return 0;
}
