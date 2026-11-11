#include<bits/stdc++.h>
using namespace std;

long long a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=a[1];
	int ans=-1e8,res=1;
	for(int i=2;i<=n;i++){
		cnt+=a[i];
		res++;
		while(m<=a[i]*res-cnt){
			int x=i-res+1;
			cnt-=a[x];
			res--;
		}
		ans=max(ans,res);
	}
	ans=max(ans,res);
	cout<<ans;
	return 0;
} 
