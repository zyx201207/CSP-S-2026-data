#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000005],f[2000005],dis[2000005];
void sl(){
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			f[j]=dis[j]=0;
		}
//		cout<<i<<endl;
		deque<int> q;
		q.push_back(i);
		int c[3]={},s[3]={};
		c[0]++,s[0]++;
		for (int j=i+1;j<=n;j++){
			if (a[j]-a[j-1]>d) break;
			while (a[q.front()]+d<a[j]){
				c[f[q.front()]]--;
				s[f[q.front()]]--;
				q.pop_front();
			}
			if (c[0]<=0 && c[1]<=0 && c[2]<=0){
				c[0]=s[0],c[1]=s[1],c[2]=s[2];
			}
			dis[j]=dis[q.front()]+1;
			int x=3*c[2]+2*c[1]+c[0]-1;
			f[j]=min(2ll,x);
			if (f[j]==1){
//				cout<<i<<" "<<j<<endl;
				ans++;
			}
//			cout<<i<<" "<<j<<" "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<f[j]<<" "<<q.front()<<endl;
			q.push_back(j);
			s[f[j]]++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>_>>_;
	while (_--){
		sl();
	}
} 
/*
1 1
6 2
-4 -3 -2 -1 3 6

*/
