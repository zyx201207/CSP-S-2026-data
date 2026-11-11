#include <bits/stdc++.h>
using namespace std;
long long a[100005],c[100005],st,ed,n,m,MMAAXX=1;
void dfs(int cur,int sum=0){
	if (cur==ed-st+1){
		long long cnt=1,Max=1,k=c[1];
		for (int i=2;i<=n;i++){
			if (c[i]==k){
				cnt++;
			}else{
				Max=max(Max,cnt);
				cnt=1,k=c[i];
			}
		}
		MMAAXX=max(MMAAXX,Max);
		return;
	}
	for (int i=1;i<=m-sum;i++){
		c[cur]=a[cur]+i;
		dfs(cur+1,sum+i);
	}
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool b=1;
	long long k;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	k=a[2]-a[1];
	for (int i=3;i<=n;i++){
		if (a[i]-a[i-1]!=k){
			b=0;
			break;
		}
	}
	if (b){
		for (int i=n;i>=1;i--){
			if ((a[1]+a[i])/2*i<=m){
				cout << min(i+1ll,n);
				break;
			
			}

		}		
	}else{
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				st=i,ed=j;
				dfs(i);
			}
		}
		cout << MMAAXX+1;
		
	}
	return 0;
} 
