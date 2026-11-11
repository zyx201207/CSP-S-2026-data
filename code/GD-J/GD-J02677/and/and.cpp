#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long a[N];
int n,m;
long long sum=LONG_LONG_MAX;
long long ans=0;
bool ck=1;

void dfs(int s,int st){
	if(s==m){
		ans=max(ans,sum);
		return;
	}
	
	for(int i=st; i<=n; i++){
		long long s1=sum;
		sum&=a[i];
		dfs(s+1,i+1);
		sum=s1;
	}
}

bool cmp1(long long aa,long long bb){
	return aa>bb;
}

bool cmp(long long x,long long y){
	x&=LONG_LONG_MAX; y&=LONG_LONG_MAX;
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		long long s=1;
		if(!ck) continue;
		bool ck1=0;
		for(int j=1; j<=20; j++){
			s*=j;
			if(s-1==a[i]){
				ck1=1;
				break;
			}
		}
		ck=ck1;
	}
	
	if(n<=2000){
		dfs(0,1);
	}
	
	else{
		if(m==n-1){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=m; j++){
					if(a[i]==a[j]) continue;
					sum=(sum&a[j]);
				}
				ans=max(ans,sum);
			}
		}
		else if(ck){
			sort(a+1,a+n+1,cmp1);
			cout<<a[m];
			return 0;
		}
		else{
			long long kkk1=LONG_LONG_MAX;
			sort(a+1,a+n+1,cmp);
			for(int i=1; i<=n-m; i++){
				long long ssss=LONG_LONG_MAX;
				for(int j=i; j<=i+m; j++) ssss&=a[i];
				kkk1=max(ssss,kkk1);
			}
			cout<<kkk1<<'\n'; 
			return 0;
		}
	}
	
	cout<<ans<<'\n';
	return 0;
}

