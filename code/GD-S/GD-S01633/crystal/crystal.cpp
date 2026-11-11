#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N],n,m,sum,cnt,mx=1,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum=1;
		cnt=0;
		if(a[i]-a[1]>m)break;
		if(a[i]-s[i-1]<=m){
			if(i>mx)mx=i;
			continue;
		}
		for(int j=1;j<i;j++){
			if(cnt+a[i]-a[j]<=m){
				cnt+=a[i]-a[j];
				sum++;	
				mx=max(mx,sum);			
			}
			else break;
		}
	}
	cout<<mx;
	return 0;
}
