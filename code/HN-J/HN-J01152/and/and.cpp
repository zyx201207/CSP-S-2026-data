#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+5;
int n,m,a[MAX_N],maxx=-1,c,d=0,t[31];
priority_queue<int> b[31];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	t[0]=1;
	for(int i=1;i<=30;i++){
		t[i]=t[i-1]<<1;
	}
	c=a[n];
	for(int j=0;j<=30;j++){
		if(c==0)break;
		if(c&1)b[j].push(a[n]);
		c>>=1;
		maxx=j;
	}
	if(maxx==-1){
		cout<<0<<"\n";
		return 0;
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]<=d)break;
		c=a[i];
		for(int j=0;j<=30;j++){
			if(c&1)b[j].push(a[i]);
			c>>=1;
			if(c==0)break;
		}
		if(d==0&&a[i]<=t[maxx])maxx--;
		if(maxx==-1){
			cout<<0<<"\n";
			return 0;
		}
		while(b[maxx].size()>=m){
			d+=t[maxx];
			maxx--;
		}	
	}
	
	cout<<d<<"\n";
	return 0;
}
