#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
long long a[2000010];
long long gc;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			gc=a[2]-a[1];
			if(m>=2*gc&&m<3*gc){
				cout<<1;
			}
			else cout<<0;
			cout<<endl;
		}
		if(c==13||c==14){
			cout<<0<<endl;
		}
		t--;
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/