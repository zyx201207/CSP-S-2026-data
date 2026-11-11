#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
long long n,m,a[MAXN],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=0,t=m;
		for(int j=i;j>=1;j--){
			if(t>=a[i]-a[j]){
				t-=a[i]-a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

