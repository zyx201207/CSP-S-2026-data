//GZ-J00047 贵阳市第一中学 刘一萱 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
const int M=2e7+5;
ll n,m,a[N],sum1,a3,maxn,cnt,w[M][35],sum2[33],q[M];
bool cmp(int a1,int a2){
	for (int i=max(q[a1],q[a2]);i>=1;i--){
		if (sum2[i]>=m){
			if (w[a1][i]>w[a2][i]){
				return 1;
			}
			else if (w[a1][i]<w[a2][i]){
				return 0;
			}
		}
	}
	return q[a1]>q[a2];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		cnt=1;
		a3=a[i];
		while(a3){
			if (a3&1){
				w[a[i]][cnt]=1;
				sum2[cnt]++;
				maxn=max(maxn,cnt);
			}
			a3>>=1;
			cnt++;
		}
		q[a[i]]=cnt;
		sum1+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum=a[1];
	for (int i=1;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
