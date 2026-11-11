#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],yuan;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		cin>>n>>d;
		for(int j = 1;j<=n;j++){
			cin>>x[j];
		}
		int cha = x[n]-x[n-1];
		int maxn = 0,cnt = 0;
		for(int j = 1;j<=n;j++){
			if(maxn+cha<=d){
				maxn+=cha;
				cnt++;
			}
		}
		if(n>=cnt+4){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}

	return 0;
}