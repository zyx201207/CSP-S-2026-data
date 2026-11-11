#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],p[500005];
deque<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,cnt=1,sum=0,l=1;
	for(int i=1;i<n;i++){
		sum=a[i+1]-a[i];
		q.push_back(sum);
		p[i]+=p[i-1]+sum*cnt;
		cnt++;
		if(p[i]>m){
			int end=0;
			while(!q.empty()&&p[i]>m){
				if(q.front()<q.back()){
					cnt--;
					end=1;
					break;
				}else{
					q.pop_front();
					p[i]-=a[i]-a[l];
					l++;
					cnt--;
				}
			}
			if(end==1){
				ans=max(ans,cnt);
				cnt=2;
				p[i]=sum;
				l=i;
				q.clear();
				q.push_back(sum);
			}
		}
	}
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}
