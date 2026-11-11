#include<bits/stdc++.h>
using namespace std;
const int MAXN=500002;
long long a[MAXN];
int dp[MAXN];
long long cz[MAXN]; 
int n,m;

void the_cz(int s){
	for(int i=0;i<n;i++){
		cz[i]=abs(a[i]-s);
	}
}

int lamn(){
	int k=1;
	for(int i=0;i<n;i++){
		if(cz[i]!=0){
			k=1;
			break;
		}
		k=0;
	}
	if(k==1)
	return 1;
	return 0;
}

int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		the_cz(a[i]);
		sort(cz,cz+n);
		int cnt=0;
		int p=m;
		while(p>0){
			if(cz[cnt]!=0)
				if(p>=cz[cnt]){
					p-=cz[cnt];
					cz[cnt]=0;
				}else{
					break;
				}
			cnt=cnt+1;
			dp[i]=dp[i]+1;
			p++;
			int x=lamn();
			if(x==0){
				cout<<n;
				return 0;
			}
		}
		cout<<dp[i]<<" ";
		for(int i=0;i<n;i++)
			cz[i]=0;
	}
	cout<<endl;
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}

