#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],t,f;
long long ans;
int check(int x,int y){
	if(x==y)return 1;
	int ans=0;
	for(int i=1;i<=min(m,y-x);i++){
		ans+=check(x+i,y);
	}return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>f>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}for(int i=1;i<n-m;i++){
			for(int j=i+m;j<=n;j++){
				if(check(a[i],a[j])==2)ans++;
			}
		}cout<<ans<<"\n";
	}

	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

