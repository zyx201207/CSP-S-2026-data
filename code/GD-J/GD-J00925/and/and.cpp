#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
int h[40],p[40];
void k(int x){
	memset(h,0,sizeof(h));
	int t=0;
	while(x){
		h[++t]=x%2;
		x/=2;
	}
	for(int i=1;i<=t;i++){
		p[t-i+1]+=h[i];
		cout<<h[t-i+1];
	}
	cout<<endl;
	maxn=max(maxn,t);
	return;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		k(x);
	}
	int ans=0;
	for(int i=maxn;i>=1;i--){
		cout<<p[i]<<endl;
		if(p[i]>=m){
			ans+=pow(2,i-1);
			cout<<i<<" "<<ans<<endl;
		}
	}
	cout<<ans<<" "<<maxn;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
