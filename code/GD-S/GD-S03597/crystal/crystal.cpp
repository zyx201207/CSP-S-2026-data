#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
long long n,m,midd,mid1,cnt=0,minn; 
long long a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n%2==0){
		midd=a[n/2];
		mid1=n/2;	
	}else{
		midd=a[n/2+1]; 
		mid1=n/2+1;	
	}
	while(1){
		minn=9999;
		for(int i=1;i<=n;i++){
			 
			if(a[i]==midd){
				continue;
			}else{
				if((max(a[i],midd)-min(a[i],midd))<minn){
					minn=(max(a[i],midd)-min(a[i],midd));
				} 
			}
		}
		if(m<minn) break;
		for(int i=1;i<=n;i++){
			if(m<minn) break;
			if(max(a[i],midd)-min(a[i],midd)==minn){
				a[i]=midd;
				m-=minn;
			}
		}	
	} 
	for(int i=1;i<=n;i++){
		if(a[i]==midd)cnt++;
	}
	cout<<cnt;
	return 0;
}
