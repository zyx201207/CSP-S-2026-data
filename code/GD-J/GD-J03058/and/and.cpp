#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,m;
long long a[200005];
long long x[200005][100];
long long d[100];
long long ans[100];
long long dp[200005];
long long answer;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		int q=a[i];
		int ip=1;
		while(q>0){
			x[i][ip]=q%2;
			q/=2;
			d[ip]+=x[i][ip];
			ip++;
			
		}
	}
	int op=0;
	for(int i=1;i<=32;i++){
		if(d[i]>=m){
			op=i;
		}
		
	}
	
	if(op==0){                                   // 特判 
		cout << 0;
		return 0;
	}
	
	int v=1;
	if(d[op]==m){                                // 特判 
		for(int i=1;i<=n;i++){
			if(x[i][op]==1){
				dp[v]=i;
				v++;
			}
		}
		v--;
		for(int i=1;i<=op;i++){
			ans[i]=1;
			for(int j=1;j<=v;j++){
				if(x[dp[j]][i]==0){
					ans[i]=0;
				}
			}
		}
		
		for(int i=1;i<=op+1;i++){
			answer+=pow(2,i-1)*ans[i];
		}
		cout << answer;
		return 0;
	}
	                                             // op指最高位 
	long long alive[200005];
	memset(alive,0,sizeof(alive));
	                                             // dp
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(x[i][op]==1){
			alive[cnt]=i;
			cnt++;
		}
	}
	int opop=op;
	while(op>=1){
		int index=1;                             // index
		for(int i=1;i<=cnt;i++){
			if(x[alive[i]][op]==1){
				dp[index]=i;
				index++;
			}
		}
		if(index-1==m){
			for(int i=1;i<=op;i++){
				ans[i]=1;
				for(int j=1;j<=index-1;j++){
					if(x[dp[j]][i]==0){
						ans[i]=0;
					}
				}
			}
			
			for(int i=1;i<=op+1;i++){
				answer+=pow(2,i-1)*ans[i];
			}
			cout << answer;
			return 0;
		}
		
		
		if(index-1>m)
		{
			memset(alive,0,sizeof(alive));
			int ind=1;
			for(int i=1;i<=index-1;i++)
			{
				alive[ind]=dp[i];
				ind++;
			}
			memset(dp,0,sizeof(dp));
		}
		
		
		
		
		op--;
	}
	
	for(int i=1;i<=opop;i++)
	{
		ans[i]=1;
		for(auto j : alive)
		{
			if(x[j][i]==0)
			{
				ans[i]=0;
			}
		}
	}
	
	for(int i=1;i<=op+1;i++)
	{
		answer+=pow(2,i-1)*ans[i];
	}
	cout << answer;
	
	return 0;
}
