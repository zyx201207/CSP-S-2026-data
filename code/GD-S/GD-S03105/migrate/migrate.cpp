#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[11451454],k[11451454],n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		memset(k,0,sizeof(k));
		for(int j=1;j<=n;j++){
			cin>>x[j];
			k[x[j]]++;
		}
		if(d==1)cout<<0;
		else{
			int num=0;
			for(int j=1;j<=n;j++){
				if(k[x[j]+(d*2)-1]&&((k[x[j]+d-1])||(k[x[j]+d]))){
					num++;
					//cout<<x[j]<<"->"<<x[j]+(d*2)-1<<" ";
				}
			}
			cout<<num;
		}
		cout<<endl;
	}

	return 0;
}
/*
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
