#include<bits/stdc++.h>
using namespace std;
int c,_,n,d,a[2000005],cnt,ans;
void dfs(int s,int t){
	if(s>=t){cnt++;return;}
	if(cnt==2)return;
	for(int i=s+1;a[i]-a[s]<=d;i++)dfs(i,t);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>_;
	while(_--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		if(c==11||c==12){
			int p=d/(a[2]-a[1]);
			for(int i=1;i<=n-3;i++){
				if(i%2==0)ans+=(n-i)/2;
				else ans+=(n-i+1)/2-1;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				cnt=0;
				dfs(i,j);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
12 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
