#include <bits/stdc++.h>
using namespace std;
long long n,ans[1000005];
long long m,a[1000005];
bool t=1,h=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)t=0;
		if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2])h=0;
	}
	if(t){
		long long w=1;
		while(1){
			if(w*w+w>2*m || w==n) break;
			w++;
		}
		cout<<w;
		return 0;
	}
	sort(a+1,a+n+1);
	if(h){
		long long d=a[2]-a[1],w=1;
		while(1){
			if(d*w*(w+1)>2*m || w==n) break;
			w++;
		}
		cout<<w;
		return 0;
	}
	
		
	ans[0]=ans[1]=1;
	for(int i=2;i<=n;i++){
		ans[i]=1;
		long long r=0,x=m;
		for(int j=i-1;j>0;j--){
			r+=a[i]-a[j];
			if(r<=m){
				ans[i]++;
				x-=r;
			}
			else break;
		}
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n];

	return 0;
}
