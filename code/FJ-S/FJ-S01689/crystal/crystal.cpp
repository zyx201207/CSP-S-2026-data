#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
const long long INF = 1e12;
long long n,m,cnt,ans;
long long a[maxn];
int hnt;
struct node{
	int f;
	long long idx;
};
node check(long long x){
	node q;
	cnt=0;
	q.f=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			break;
		}
		cnt+=(x-a[i]);
		q.idx=i;
		//cout<<"cnt:"<<cnt<<" q.idx:"<<q.idx;
	}
	if(cnt>m)q.f=1;
	else if(q.idx<=1)q.f=2;
	return q;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==0){
		cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;
				ans=max(ans,cnt);
			}else{
				cnt=1;
			}
		}
		if(ans==1)cout<<0;
		else cout<<ans;
		return 0;
	}
	long long l=-INF,r=INF;
	while(l<=r){
		cout<<++hnt<<":";
		long long mid=l+r>>1;
		node p=check(mid);
		if(p.f==0||p.f==2){
			ans=max(ans,p.idx);
			l=mid+1;
		}else{
			r=mid-1;
		}
		//cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<" p.f:"<<p.f<<" p.idx:"<<p.idx<<"cnt:"<<cnt<<"\n";
	}
	if(ans<=1)cout<<0;
	else cout<<ans;
	return 0;
}

