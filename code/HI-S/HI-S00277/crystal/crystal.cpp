#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;

long long n,ans=1;
long long m;
long long a[maxn];

void solve_n5000(){
	for(int i=1;i<=n;i++){
		long long mm=m;
		long long ji=1;
		for(int j=i-1;j>=1;j--){
			if(mm-(a[i]-a[j])>=0){
				ji++;
				mm=mm-(a[i]-a[j]);
			}else break;
		}
		ans=max(ans,ji);
	}	
}

void solve_a100(){
	int b[300];
	for(int i=0;i<=200;i++) b[i]=0;
	for(int i=1;i<=n;i++){
		int cnt=(int)a[i]+100;
		b[cnt]++;
	}
	vector<pair<int,int>> c; 
	for(int i=0;i<=200;i++) if(b[i]!=0) c.push_back({i,b[i]});
	for(int i=0;i<(int)c.size();i++){
		long long mm=m;
		long long ji=c[i].second;
		for(int j=i-1;j>=1;j--){
			if(mm-(c[i].first-c[j].first)*c[j].second>=0){
				ji+=c[j].second;
				mm=mm-(c[i].first-c[j].first)*c[j].second;
			}else {
				int cnt=c[j].second-1;
				while(cnt){
					if(mm-(c[i].first-c[j].first)*cnt>=0){
						ji+=cnt;
						break;
					}else cnt--;
				}
				break;
			}
		}
		ans=max(ans,ji);		
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		solve_n5000();
	}else if(a[n]<=100){
		solve_a100();
	}else{
		if(a[1]==1&&a[n]==n){
			long long j=n*(n-1)/2;
			if(m>=j) ans=n;
			else{
				for(int i=n-1;i>=1;i--){
					if(j-i<m) j-=i;
					else{
						ans=i+1;
						break;
					}
				}
			}
		}else{
			long long j=n*(n-1)/2*(a[2]-a[1]);
			if(m>=j) ans=n;
			else{
				for(int i=n-1;i>=1;i--){
					if(j-i*(a[2]-a[1])<m) j=j-(a[2]-a[1])*i;
					else{
						ans=i+1;
						break;
					}
				}
			}			
		}
	} 
	cout<<ans;
	return 0;
}
