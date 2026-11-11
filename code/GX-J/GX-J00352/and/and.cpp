#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	long long aaa;
	for(int i=0;i<n;i++){
		scanf("%lld",&aaa);
		if(aaa>ans){
			ans=aaa;
		}
	}
	printf("%lld",ans);
}
