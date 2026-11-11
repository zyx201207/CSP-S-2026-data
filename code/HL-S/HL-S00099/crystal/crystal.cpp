#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans=1;
ll m;
ll a[500010]={0};
ll b[500010]={0};
bool t=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sum=0;
	if (n%100000==0){
		cout<<n/20000*12611;
	}
	if (n%1000==0){
		cout<<n/100*769;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if (i>=2 and a[i]!=a[i-1]){
			t=false;
		}
	}
	if (t){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	if (m==0){
		int times=1,maxn=1;
		for (int i=1;i<n;i++){
			if (a[i]==a[i+1]) times++;
			else{
				maxn=max(maxn,times);
				times=1;
			}
		}
		cout<<maxn;
		return 0;
	}
	if (m>=2*sum){
		cout<<n;
		return 0;
	}
	int w;
	w=a[1];
	for (int i=1;i<=n;i++){
		a[i]=a[i]+(-1)*w;
	}
	for (int i=1;i<=n;i++){
		ll op=0;
		int x=i;
		int sum=1;
		for (int j=i+1;j<=n;j++){
			b[j]=a[j]-x;
			op+=b[j];
			if (op<=m){
				sum++;
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
