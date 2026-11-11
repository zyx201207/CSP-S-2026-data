#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500002],d[500002];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("t.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);bool f=1;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}for(int i=2;i<=n;i++)if(d[i]!=d[i-1])f=0;
	
	if(f){//d
		ll t=m*2/d[1];
		double x=sqrt(t);int ans=int(x);
		while(ans*ans+ans>t)ans--;
		cout<<ans+1;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		for(int){
//			dp[]
//		}
//	}
	
	
	return 0;
} 
