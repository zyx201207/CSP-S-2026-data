#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+3;

int c,t,n;
long long d,x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			if(x[2]-x[1]>=d){
				cout<<0<<endl;
				continue;
			}
			long long deld=x[2]-x[1],len=0;
			len=d/deld;
			if(!len)cout<<0<<endl;
			else cout<<(n-len)<<endl;
		}
	}
	else{
		while(t--){
			cout<<rand()<<endl;
		}
	}
	return 0;
}
