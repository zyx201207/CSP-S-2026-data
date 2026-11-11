#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005];
vector<int> v[300005];
int low_bit(int x){
	return x&-x;
}
void zf(int l,int k){
	while(l<=n){
		c[l]+=k;
		l+=lowbit(l);
	}	
	return ;
}
int huanyaun(int x){
	int ans;
	while(x>0){
		ans+=c[x];
		x-=low_bit(x);
	}
	return ans;
}
huanyuan()
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		if(v[a[i]].empty()) b[a[i]]=i;
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		zf(b[i],-1);
		zf(v[a[i]].back(),1);
	}
	for(int i=1;i<=n;i++){
		int t=v[a[i]].back();
		v.pop_back();
	}
	return 0;
} 
