#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int a[2000006];
map<long long,long long> id;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		map<long long,long long> id;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			id[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			if(id[a[i]+m+m-1]&&id[a[i]+m]&&id[a[i]+m-1]){
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
} 
/*
0 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
*/
