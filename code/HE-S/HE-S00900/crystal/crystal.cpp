#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll sum[500005];
ll ans=0,cnt;
ll maxans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		sum[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		cnt=0;
		ans=0;
		for(int j=i;j<=n-1;j++){
			ans++;
			cnt+=sum[j]*ans;
			if(cnt>m){
				maxans=max(maxans,ans);
				break;
			}	
		} 
	}
	cout<<maxans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7*/
