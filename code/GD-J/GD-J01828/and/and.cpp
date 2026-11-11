#include <bits/stdc++.h>
using namespace std;
int n , K;
long long a[200005];
long long Cnt[200005][35];
bool cmp(long long a , long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n>>K;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long x=a[i];
		int Pos=0;
		while(x>0){
			Pos++;
			if(x&1){
				Cnt[i][Pos]++;
			}
			x>>=1;
		}
	}
	for(int j=1;j<=31;j++){
		for(int i=1;i<=n;i++){
			Cnt[i][j]+=Cnt[i-1][j];
		}
	}
	long long ans=0;
	for(int i=K;i<=n;i++){
		long long now=0;
		for(int j=1;j<=31;j++){
			if(Cnt[i][j]-Cnt[i-K][j]>=K){
				now+=(1<<(j-1));
			}
		}
		ans=max(ans,now); 
	}
	cout <<ans;
	return 0;
}
