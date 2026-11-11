#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=30;k>=0;k--){
		int x=0;
		for(int i=1;i<=n;i++){
			if(a[i]==-1) continue;
			if((a[i]>>k)&1) x++;
		}
		if(x>=m){
			for(int i=1;i<=n;i++){
				if(a[i]==-1) continue;
				if(!((a[i]>>k)&1)) a[i]=-1;
			}
			ans+=pow(2,k);
		}
	}
	cout<<ans;
	return 0;
}
