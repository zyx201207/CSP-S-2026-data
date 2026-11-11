#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool t[500005];
long long ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	memset(t,0,sizeof(t));
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long k=0;k<n;k++){
		vector<long long> v;
		for(long long i=k;i<n;i++){
			if(t[a[i]]==0){
				t[a[i]]=1;
				v.push_back(a[i]);
			}
			else{
				while(v[v.size()-1]!=a[i]){
					t[v[v.size()-1]]=0;
					v.pop_back();
				}
				v.push_back(a[i]);
				t[a[i]]=1;
			}
		}
		for(long long j=1;j<=m;j++){
				if(t[j]!=0){
					ans[j]++;
				}
			}
		memset(t,0,sizeof(t));
	}
	
	
	for(long long i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
