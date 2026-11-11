#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll =long long;
ll n,m,a[N],c[N],in[N],o[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool fl=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]){
			fl=0;
		}
	}
	if(n<=5000){
		for(int i=1;i<=n;i++) {
			stack<ll>sk;
			sk.push(a[i]);
			in[a[i]]=1;
			for(int j=i+1;j<=n;j++) {
				if(in[a[j]]){
					while(sk.size()&&sk.top()!=a[j]){
						in[sk.top()]=0;
						sk.pop();
					}
				}else{
					sk.push(a[j]);
					in[a[j]]=1;
				}
			}
			while(sk.size()){
				c[sk.top()]++;
				in[sk.top()]=0;
				sk.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		return 0;
	}
	if(fl){
		for(int i=1;i<=m;i++){
			int k=upper_bound(a+1,a+1+n,i)-a-1;
			c[i]=k;
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<' ';
		}
		return 0;
	}
}
