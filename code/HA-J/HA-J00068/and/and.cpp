#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans;
vector<int>vt,vt1;
struct node{
	bitset<32>b;
	void add(int x){
		int d=1,i=1;
		while(d<=x){
			b[i]=(d&x);
			d<<=1;
			i++;
		}
	}
}c[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i].add(a[i]);
	}
	int cnt=0,k=0;
	for(int j=30;j>=1;j--){
		cnt=0;
		vt.clear();
		for(int i=1;i<=n;i++){
			if(c[i].b[j]){
				cnt++;
				vt.emplace_back(i);
			}
		}
		if(cnt>=m){
			k=j;
			ans=(1<<(k-1));
			break;
		}
	}
	for(int j=k-1;j>=1;j--){
		cnt=0;
		vt1=vt;
		vt.clear();
		for(int&i:vt1){
			if(c[i].b[j]){
				cnt++;
				vt.emplace_back(i);
			}
		}
		if(cnt>=m){
			ans+=(1<<(j-1));
		}
		else{
			vt=vt1;
		}
	}
	cout<<ans;
	return 0;
}