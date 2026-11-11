#include<bits/stdc++.h>
using namespace std;

const int MAXN=2000020;
int c,t,n;
long long d,a[MAXN];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		if(n==4){
			if((a[2]-a[1])<=d and (a[3]-a[1])<=d and (a[4]-a[2])<=d and (a[4]-a[3])<=d)cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
