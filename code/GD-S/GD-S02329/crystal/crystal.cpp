#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ma=-1,cha;
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2 and f){
			if(a[i]-a[i-1]!=a[2]-a[1])
				f=0;
		} 
	}
	cha=a[2]-a[1];
	if(n==1){
		cout<<1;
		return 0;
	}
	if(f){
		int k=0,j=0;
		while(m>=0 and j<=n){
			j++;
			if(j%2) k+=cha;
			m-=k;
		}
		cout<<j;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=m,j=i;
		while(cnt>=0 and j<=n){
			j++;
			cnt-=(a[j]-a[i]);
			cout<<1;
		}
		ma=max(ma,j-i);	
	} 
	
	reverse(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		int cnt=m,j=i;
		while(cnt>=0 and j<=n){
			j++;
			cnt-=(a[i]-a[j]);
		}
		ma=max(ma,j-i);	
	} 
	
	cout<<ma;
	
	return 0;
}
