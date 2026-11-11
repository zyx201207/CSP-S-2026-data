#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],lt[300010],b[300010];
signed main(){
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(lt[a[i]]){
			bool is_changed[500010];
			for(int j=i-1;j>lt[a[i]];j--){
				if(!is_changed[a[j]]){
					b[a[j]]=max(b[a[j]],lt[a[i]]);
				}
			}
		}
		if(b[a[i]]&&lt[b[a[i]]]<i){
			lt[a[i]]=i;
			b[a[i]]=0;
		}
		else{
			lt[a[i]]=i;
		}
	}
	
	for(int i=1;i<=m;i++){
		int t=lt[i]-b[i];
		 
		printf("%lld ",t);
	}
	return 0;
}
