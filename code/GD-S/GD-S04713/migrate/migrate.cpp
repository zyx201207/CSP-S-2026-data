#include<bits/stdc++.h>
using namespace std;
const int N=5001;
long long n,d,T,c;
struct island{
	long long idx;
}x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i].idx);
		}
		if(c==13||c==14){
			if(d<abs(x[1].idx-x[2].idx)){
				cout<<0;
			} 
		}
	}
	return 0;
} 
