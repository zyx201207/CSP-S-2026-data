#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "crystal"
const int N=5e5+5;
int n,m,ans;
int a[N];
int dif[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cin.tie(0);
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){ cout<<1; return 0;}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dif[i]=a[i]-a[i-1];
	}
	int k=0,site=1;
	for(int j=1;j<=n;j++){ //起点 
		int last=0,cost,sum=0;
		for(int i=1;i<n;i++){ //长度 
			site=j+i-1;
			cost=k*dif[site]+last;
			if(cost>=m){
				ans=site;
				if(cost>m){
					sum--;
				}
				int p=site+1;
				while(a[p]==a[site]){
					sum++;
					p++;
				}
				ans=max(sum,ans);
				break;
			}
			k++;
			last=cost;
		}
	}
	cout<<ans-1;
	
	

		

	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
1 2 8 9 10
*/
