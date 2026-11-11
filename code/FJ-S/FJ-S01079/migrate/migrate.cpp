#include<bits/stdc++.h>//migrate
using namespace std;
#define ll long long
#define vv vector
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vv<int> x(n),cha(n),pre(n);
		cha[0]=0;
		pre[0]=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(i!=0)cha[i]=x[i]-x[i-1];
		}
		ll sum=0;
		ll num=0;
		for(int i=1;i<n;i++)if(cha[1]==cha[i])num++;
		if(num==n-1){
			if(cha[1]==d){
				cout<<0<<'\n';
				continue;
			}
		}
		for(int i=1;i<n;i++){
			pre[i]=pre[i-1]+cha[i];
			if(pre[i]==d)sum++;
			else if(pre[i]>d){
				pre[i]-=pre[i-1];
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 1
4 2
1 3 5 7
*/
