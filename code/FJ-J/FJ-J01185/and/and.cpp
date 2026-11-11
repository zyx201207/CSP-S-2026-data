#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans;
int n,m,cnt[35]; 
vector<int> v[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=0;j<32;j++){
			if((a[i]>>j) & 1){
				v[j].push_back(i);
			}
		} 
	}
	for(int i=32;i>=0;i--){
		if(v[i].size()<m) continue;
		ans+=(1LL<<i);
		//cout<<i<<endl; 
		for(int x=i-1;x>=0;x--) v[x].clear();
		for(auto k : v[i]){
			for(int j=0;j<i;j++){
				if((a[k]>>j) & 1){
					v[j].push_back(k);
				}
			}	 
		}
	}
	printf("%lld",ans);
	return 0;
}

