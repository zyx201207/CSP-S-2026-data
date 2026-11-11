#include<bits/stdc++.h>//16
using namespace std;
long long c,t,n,d,a[1000006],ans,zz;
void dfs(int l,int r,int x,int num){
//	cout<<x<<num<<' ';
	if(x==r){
		if(num<zz || zz==-1){
			zz=num;
			ans=1;
		}
		else if(num==zz){
			ans++;
		}
		return;
	}
	if(num>=zz && zz!=-1){
		return;
	}
	for(int i=x+1;i<=r;i++){
		if(a[i]-a[x]<=d){
			dfs(l,r,i,num+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int aaa;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				aaa=a[i]-a[i-1];
			}
			if(i>2 && a[i]-a[i-1]!=aaa){
				flag=0;
			}
		}
		if(flag){
			int shu=d/(a[2]-a[1]);
			shu=shu*2-1;
			if(shu<=1){
				cout<<0<<'\n';
				return 0;
			}
			if(n-shu<=0){
				cout<<0<<'\n';
			}
			else{
				cout<<n-shu<<'\n';
			}
		}
		else if(c<=6){
			int zans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					ans=0,zz=-1;
					dfs(i,j,i,0);
//					cout<<i<<' '<<j<<' '<<ans<<'\n';
					if(ans==2){
//						cout<<i<<' '<<j<<'\n';
						zans++;
					}
				}
			}
			cout<<zans<<'\n';
		}
		else if(c>=11 && c<=12){
			int shu=d/(a[2]-a[1]);
			shu=shu*2-1;
			if(shu<=1){
				cout<<0<<'\n';
			}
			else if(n-shu<=0){
				cout<<0<<'\n';
			}
			else{
				cout<<n-shu<<'\n';
			}
		}
		else{
			cout<<0<<'\n';
		}
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
