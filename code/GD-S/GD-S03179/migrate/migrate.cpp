#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e6+10,inf=2e18+10;
LL c,x[N],n,d,k[N];
bool check(int a,int b){
	LL road=1,minstep=1;
	int lst=a;
	bool f=0;
	for(int i=a;i<=b;i++){
		if(i!=a&&abs(x[i]-x[i-1])>d){
			f=1;break;
		}
		if(abs(x[i]-x[lst])>d){
			minstep++;
			lst=i-1;
		}
	}
	if(f==1) return 0;
	for(int i=a;i<=b;i++){
		road*=k[i];
	}
	if(road==2) return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		LL ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[i]+d>x[j]){
					k[i]++;
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}

