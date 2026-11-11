#include<bits/stdc++.h>
using namespace std;
long long maxa,a[500010];
int sum[210];
unsigned long long solve(unsigned long long s,unsigned long long t){
	return (sqrt(s*s+8*s*t)-s)/(2*s);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	unsigned long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(abs(a[i]),maxa);
	}
	sort(a+1,a+n+1);
	if(maxa<=100){
		for(int i=1;i<=n;i++)
			sum[a[i]+101]++;
		int ans=0;
		for(int i=1;i<=201;i++){
			int tg=i-1,cnt=sum[i];
			long long cur=m;
			while(tg>0&&cur>0){
				if(sum[tg]*(i-tg)<=cur){
					cnt+=sum[tg];
					cur-=sum[tg]*(i-tg);
					tg--;
				}
				else{
					cnt+=(cur/(i-tg));
					cur=0;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<endl;
		return 0;
	}
	unsigned long long d;
	bool flag=1;
	for(int i=2;i<=n;i++){
		if(i==2)
			d=a[2]-a[1];
		else if(a[i]-a[i-1]!=d){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<min(n,solve(d,m)+1)<<endl;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int cnt=1,tg=i-1;
		long long cur=m;
		while(tg>0&&cur>0){
			if(cur>=a[i]-a[tg]){
				cur=cur-(a[i]-a[tg]);
				tg--;
				cnt++;
			}
			else
				cur=0;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
