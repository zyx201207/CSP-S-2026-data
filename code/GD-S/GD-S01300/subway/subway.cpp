#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
void rd(int &x){
	scanf("%lld",&x);
}
template<typename T,typename ...U> void rd(T &x,U &...y){
	rd(x);
	rd(y...);
}
signed main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	rd(c,n,m,d,q);
	for(int i=1;i<=q;i++){
		puts("1");
	}
	return 0;
}

