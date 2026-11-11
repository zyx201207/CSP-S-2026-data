#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],g[300010];
bool f[300010];
stack<long long> t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long sm=1;sm<=n;sm++){
		for(long long i=sm;i<=n;i++){
			if(f[a[i]]==1){
				while(!t.empty()){
					long long x=t.top();
					if(a[i]==x){
						break;
					}
					else{
						f[x]=0;
						t.pop();
					}
				}
			}
			else{
				t.push(a[i]);
				f[a[i]]=1;
			}
		}
		for(long long i=1;i<=m;i++){
			if(f[i]==1){
				g[i]++;
			}
			f[i]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<g[i]<<" ";
	}
	return 0;
}
