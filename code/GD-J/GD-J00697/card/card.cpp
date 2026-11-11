#include<bits/stdc++.h>
using namespace std;
vector<bitset<300008> > t;
long long n,m,a[500008],nxt[500008],las[300008],sum[300008],ans[300008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		las[a[i]]=i;
		sum[a[i]]++;
	}
	bitset<300008> c;
	t.push_back(c);
	for(int i=n;i>=1;i--){
		if(las[a[i]]==i){
			nxt[i]=n+1;
		}
		else{
			nxt[i]=las[a[i]];
		}
		
		if(nxt[i]==n+1){
			bitset<300008> bs=t[n-i];
			bs[a[i]]=1;
			t.push_back(bs);
		}
		else{
			bitset<300008> bs=t[n-nxt[i]+1];
			bs[a[i]]=1;
			t.push_back(bs);
		}
		
		if(nxt[i]==n+1){
			for(int j=1;j<=m;j++){
				ans[j]+=((long long)(t[n-i+1][j])*sum[a[i]]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
//10 3
//3 1 2 1 3 2 3 1 2 1
