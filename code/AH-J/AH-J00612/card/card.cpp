#include<bits/stdc++.h>
using namespace std;
int const N=5e5+100;
long long  n,m,a[N],zt[N],ans[N];
stack<long long> s;
void takeout(long long k){
	while((s.top()!=k)&&(!s.empty())){
		s.pop();
	}
	if(!s.empty()&&s.top()==k)s.pop();
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++)zt[i]=0;
		for(int i=k;i<=n;i++){
			if(zt[a[i]]){
				takeout(a[i]);
			}
			s.push(a[i]),zt[a[i]]=1;
		}
		while(!s.empty()){
			ans[s.top()]+=1;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
