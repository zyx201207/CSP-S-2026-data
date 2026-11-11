#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;
using LL = long long;
const LL N = 5e5 + 5,M = 3e5 + 5;

LL n,a[N],m,ans[M];
deque<LL> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	for(LL i=1;i<=n;i++)	scanf("%lld",a+i);
	
	for(LL i=1;i<=n;i++){
		LL f[M]={0};
		dq.clear();
		for(LL j=i;j<=n;j++){
			f[a[j]]++;
			if(f[a[j]]==2){
				while(!dq.empty() && dq.back()==a[j])	{
					cout<<dq.back()<<endl;
					f[dq.back()]--;
					dq.pop_back();
				}
				if(!dq.empty() && dq.back()==a[j]){
					f[a[j]]--;
					dq.pop_back();
				}
			}
			dq.push_back(a[j]);
		}
		for(LL i=1;i<=m;i++)	ans[i]+=f[i];
	}
	for(LL i=1;i<=m;i++)	printf("%lld ",ans[i]);	


	return 0;
}
