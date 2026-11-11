#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long jd[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		bool f=1,f1=0,f2=0,f3=0;
		int id=0;
		for(int i=1; i<=n; i++){
			scanf("%lld",&jd[i]);
			if(i!=1&&abs(jd[i]-jd[i-1])<=d){
				f=0;
			}
			if(i!=1&&i!=n&&abs(jd[i]-jd[1])<=d&&abs(jd[i]-jd[n])<=d){
				f1=1;
				id=i;
			}else if(i==n&&abs(jd[i]-jd[1])<=d){
				f2=1;
				id=i;
			}else if(i==1&&abs(jd[i]-jd[n])<=d){
				f3=1;
				id=i;
			}
		}
		if(!f){
			cout<<0<<"\n";
			continue;
		}
		if(f1){
			cout<<(id-1)*(n-id)<<"\n";
		}else if(f2){
			cout<<0<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
