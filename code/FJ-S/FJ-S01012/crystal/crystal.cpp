#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],ans=1;
bool d,d2;

void f(long long x,long long tz,long long tot){
	if(x>n) return;
	if(tz>m) return;
	if(tot>n) return;
	if(tz<=m){
		while(a[x]==a[x+1]&&x<n) x++,tot++;
		ans=max(ans,tot);
	}
	if(tz==m||x==n||tot==n) return;
	
	if(x+1<=n) f(x+1,tz+(tot)*(a[x+1]-a[x]),tot+1); 
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) d=1;
		if(i>2) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) d2=1;
	}
	if(!d){//A
		long long t=0,tl=1;
		while(t<m){
			t+=tl; tl++;
		}
		if(t==m) cout<<tl;
		else cout<<tl-1;
		return 0;
	}
	else if(!d2){//B
		long long dc=a[2]-a[1];
		long long t=0,tl=dc;
		while(t<m){
			t+=tl; tl+=dc;
		}
		if(t==m) cout<<tl/dc;
		else cout<<tl/dc-1;
		return 0;
	}
	else {
		
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
			f(2,a[i+1]-a[i],2);
		cout<<ans;
	}
} 
