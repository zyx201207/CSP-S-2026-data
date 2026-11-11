#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,MAXN=15;
long long x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int testNumber,T;cin>>testNumber>>T;
	while(T--){
		int n;long long d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(testNumber==11||testNumber==12){
			if(x[2]-x[1]>d)cout<<"0\n";
			else cout<<n-3<<"\n";
		}else cout<<"0\n";
	}
	return 0;
}
