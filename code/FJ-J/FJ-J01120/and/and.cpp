#include<iostream>
#include<cmath>
using namespace std;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN];
long long maxn,maxlog;
bool flag[MAXN];
long long cnt=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	maxlog=log2(maxn);
	for (int i=maxlog;i>=0;i--){
		cnt=0;
		for (int j=1;j<=n;j++){
			if (!flag[j] && (a[j]>>i)&1) cnt++;
		}
		if (cnt>=m){
			ans+=(1<<i);
			for (int j=1;j<=n;j++){
				if (!((a[j]>>i)&1)) flag[j]=true;
			}
		}
	}	
	cout<<ans;
	return 0;
}
// rp++;
