#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0,ans=-4.2e9;
	scanf("%lld%lld",&n,&m);
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	long long l=0,len=1,r=0,t=a[0];
	do{
		s=len*a[r]-t;
		if(s<=m){
			ans=max(ans,len);
			r++;
			len++;
			t+=a[r];
		}else{
			t-=a[l];
			l++;
			len--;
		}
	}while(r<n);
	cout<<ans;
	return 0;
} 
