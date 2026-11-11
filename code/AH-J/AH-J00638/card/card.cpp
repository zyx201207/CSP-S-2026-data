#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[1000000],f[600000],cnt[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	for(LL i=1;i<=n;i++){
		stack<LL> zm;
		memset(f,0,sizeof f);
		for(LL j=i;j<=n;j++){
			if(f[a[j]]){
				while(zm.top()!=a[j]){
					f[zm.top()]=0;
					zm.pop();
				}
			}else{
				zm.push(a[j]);
				f[a[j]]=1;
			}
		}
		while(!zm.empty()){
			cnt[zm.top()]++;
			zm.pop();
		}
	}
	for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
