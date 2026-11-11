#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long ans[N];
long long a[N]={0},b[N]={0},f[N]={0};
stack<long long> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%ld",&ans[i]);
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[ans[j]]++;
			if(a[ans[j]]%2==0){
				a[ans[j]]--;
				while(stk.top()!=ans[j] && (!stk.empty())){
					a[stk.top()]--;
					stk.pop();
				}
			}
			else stk.push(ans[j]);
		}
		while((!stk.empty())){
			
			f[stk.top()]=1;
			stk.pop();
		}
		
		for(int i=1;i<=m;i++){
			b[i]+=f[i];
			f[i]=0;
		}
		for(int i=1;i<=n;i++) a[i]=0;
	}
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
