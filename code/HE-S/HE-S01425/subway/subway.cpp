#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll a[2000004];
void xiao(int nn,int dd){
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld",&c,&t);  //测试点编号和数据组数 
	while(t--){
		scanf("%lld%lld",&n,&d);
		if(n<4)  printf("0");
		if(n<=9) xiao(n,d);
	}
	
	return 0;
}

