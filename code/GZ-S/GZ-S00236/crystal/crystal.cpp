//贵阳市第三实验中学 赵行健 GZ-S00236 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,m,ans=1;
int a[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int now=m,nowlen=1;
	for(int i = 2;i<=n;i++){
		if(now>=(a[i]-a[i-1])*nowlen){
			now-=(a[i]-a[i-1])*nowlen;
			nowlen++;
			ans=max(ans,nowlen);
		}
		else{
			while(nowlen&&now<(a[i]-a[i-1])*nowlen){
				int last=i-nowlen;
				nowlen--;
				now+=(a[i-1]-a[last]);
			}
			now-=(a[i]-a[i-1])*nowlen;
			nowlen+=1;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 3
1 2 9 10 11
*/
