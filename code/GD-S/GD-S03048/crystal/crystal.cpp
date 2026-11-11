#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],t,sum[N];
int ans,v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		sum[i]=sum[i-1]+a[i];
//	}
	
	t=m,v=1;
	for(int i=2;i<=n;i++){
		if(t>=(a[i]-a[i-1])*v){
			t-=(a[i]-a[i-1])*v;
			v++;
		}else{
			while(t<(a[i]-a[i-1])*v){
				t+=a[i-1]-a[i-v];
				v--;
			}
//			int k=floor(((a[i]-a[i-1])*v-t)/(a[i]-a[i-1]));
//			t+=(k*a[i-1]-(sum[i-v+k-1]-sum[i-v-1]));
//			v-=k;
			t-=(a[i]-a[i-1])*v;
			v++;
		}
		ans=max(ans,v);
	}
	cout<<ans;
	return 0;
}

