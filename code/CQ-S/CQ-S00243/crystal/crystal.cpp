#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long ans=0;
	queue<int>q;
	long long sum=0;
	for(int i=1;i<=n;i++){
		while(!q.empty()&&q.size()*a[i]-sum>m){
			int x=q.front(); q.pop();
			sum-=a[x];
		}
		q.push(i); sum+=a[i];
//		cout<<q.size()<<endl;
		ans=max(ans,(long long)q.size());
	}
	cout<<ans;
	return 0;
}
/*
5 6
-100 4 5 6 7
*/
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
