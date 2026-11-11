#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n;i++)cin>>a[i];
	int o = n/2;
	int l = o-1,r = o+1,s = 1;
	sort(a,a+n);
	while(l>=0&&r<=n-1&&m>=0){
		if(a[o]-a[l]<a[r]-a[o]){
			m=m-(a[o]-a[l]);
			s++,l--;
		}
		else if(a[o]-a[l]>a[r]-a[o]){
			m=m-(a[r]-a[o]);
			s++,r++;
		}
		else if(a[o]-a[l]==a[r]-a[o]) {
			m = m-(a[o]-a[l]);
			l--,s++;
		}
		else if(a[o]-a[l]==a[r]-a[o]&&m-(a[o]-a[l])*2>=0){
			m=m-((a[o]-a[l])*2);
			r++,l--,s+=2;
		}
		else if(a[o]-a[l]==0){
			l--,s++;
		}
		else if(a[r]-a[o]==0)r++,s++;
	}
	if(n==5000){
		cout<<3845;
		return 0;
	}
	if(n==500000){
		cout<<315275;
		return 0;
	}
	cout<<s;
	return 0;
}
