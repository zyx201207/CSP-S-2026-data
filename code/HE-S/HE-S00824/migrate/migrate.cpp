#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,cnt = 0;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		long long a[n];//a:зјБъ
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		long long d1=d/(a[2]-a[1]);
		if(n<=2 || d1==1){
			cout<<0<<"\n";
		}
	}
	
	return 0;
} 
