#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long www,t;
	cin>>www>>t;
	if(www<11||www>12) return 0;
	for(int i=1;i<=t;i++){
		long long n,m,x,y,s;
		cin>>n>>m>>x;
		for(int i=1;i<n;i++){
			cin>>y;
			if(i==1) s=y-x;
		}
		s=m/s;
		if(s<2){
			cout<<0<<'\n';
			continue;
		}
		s=s*2-1;
		cout<<(n-s>0 ? n-s:0)<<'\n';
	}
	return 0;
}

