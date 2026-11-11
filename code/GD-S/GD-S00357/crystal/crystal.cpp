#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],dp[maxn],ans;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int check=0,cnt=1; 
	for(int i=2;i<=n;i++){
		check+=(a[i]-a[1]);
		if(check>m){
			if(a[i]==a[i+1]||a[i]==a[i-1]){
				cnt++;
				break;
			}else{
				break;
			}
		}
		cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
