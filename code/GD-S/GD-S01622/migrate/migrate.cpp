#include<bits/stdc++.h>
using namespace std;
const int N=2e6+8;
int c,t,n,d;
int a[N];
int minn=0x3f3f3f3f,sum=0;
void dfs(int s,int t,int cnt){
	if(s>=t){
		if(cnt<minn){
			minn=cnt;
			sum=1;
		}
		else if(cnt==minn){
			sum++;
		}
		return ;
	}
	for(int i=s+1;a[i]-a[s]<=d&&i<=t;i++){
		dfs(i,t,cnt+1);
	}
}
bool check(int s,int t){
	dfs(s,t,0);
	if(sum==2){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int num=abs(a[2]-a[1]);
			int sum=d/num;
			if(sum==1){
				cout<<0<<'\n';
				continue;
			}
			cout<<(a[n]-a[1])/num-sum+1<<'\n';
			continue;
		}
		if(c==13||c==14){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
//					cout<<i<<" "<<j<<'\n';
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
11 4
10 3
1 2 3 4 5 6 7 8 9 10
10 2
1 2 3 4 5 6 7 8 9 10
8 4
0 2 4 6 8 10 12 14
8 2
0 1 2 3 4 5 6 7

11 2
5 3
-2 -1 0 1 2
6 3
-2 0 2 4 6 8

-2 -1 0 1 
1
3

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
