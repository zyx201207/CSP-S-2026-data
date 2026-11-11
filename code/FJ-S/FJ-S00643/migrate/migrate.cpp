#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ls[2000325];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		memset(ls,0,sizeof(ls));
		cin>>n>>d;
		for (int j=1;j<=n;j++){
			cin>>ls[j];
		}
		long long num=d/(ls[2]-ls[1]);
		if (num==0||num==1){
			cout<<0<<endl;
			continue;
		}
		long long tl=n-num;
		cout<<tl<<endl;
	}
	return 0;
}
