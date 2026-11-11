#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],f[N];
int ans=1;
bool check(int l,int r){
	return 1ll*a[r]*(r-l+1)-(f[r]-f[l-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(i<n&&a[i]==a[i+1])continue;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

well,this is the competition history,aiming at to record some key things to solve.
14:30 begin!
14:45 mkdirs,see problems: T1(easy) T2(graph?!) T3(graph+DP) T4(graph?!)
15:00 successful done T1,wow!
15:10 ohno T1-test3&4 has sth.wrong,think...
15:12 find we'd first sort it,and then calc it's presum.
15:15 welldone!now have 100pts,let's see T2
15:43 still think T2
15:45 T2&T3&T4 are all graph problem!?!???!!!
16:00 still thinking. goout,calmdown
16:45 write code on T2 it's a Floyd
16:52 wow!wow!I write T2 successfully!!!!zch hope me yeah.
16:55 Now,check the longlong problem of T2.
17:05 check all the test on T2,now it's 200pts,keep it going! trust myself.
17:20 relax for 20minutes(look T3,T4),DP?
17:40 write T3 but only 8pts...
18:10 writ T4 for 5pts
18:10 I think that's fine,so check all codes
18:15 Goodbye,CSP-S2026!
*/
