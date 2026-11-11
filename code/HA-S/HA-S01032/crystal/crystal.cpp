#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
long double a[MAXN]/*cnt[MAXN],diff[MAXN]*/;
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int sum=0;
	cin>>n>>m;
	int ju;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int flag;
	ju=a[2]-a[1];
	sort(a+1,a+n+1);
	double ave=(sum*1.0)/(n*1.0);
	int cnt;
	for(int i=1;i<n;i++){
		if(a[i]<=ave&&a[i+1]>ave){
			cnt=i;
		}
	}
	int k;

	if(abs(ave-a[cnt])>=abs(a[cnt+1]-ave))k=a[cnt+1],cnt=cnt+1;
	else k=a[cnt];
	int k1=0;
	for(int i=cnt+1;i<=n;i++){
		if(a[i]==k){
			k1++;
		}
	}
	int s=0;
	cout<<cnt+k1; 
	return 0;
}

