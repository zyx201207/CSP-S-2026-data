#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long a[N],b[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,cnt=1,ans=0,maxn=-1,s=0;
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
	    }
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		b[1]=a[1];
		for(int i=1;i<=n;i++){
			cnt=1;
			ans=0;
			for(int j=i;j<=n;j++){
				sum[j]=b[j]*(cnt-1)+sum[j-1];
				if(sum[j]>m){
					break;
				}
				cnt++;
				ans++;
	    	}
	    	maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	else{
		cnt=0;
		for(int i=1;i<=n;i++){
			s+=i;
			if(s<=m){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
