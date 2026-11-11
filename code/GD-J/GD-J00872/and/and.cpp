#include<bits/stdc++.h>
using namespace std;
int n,k,m[200005];
long long a[200005],maxx=-1;
int sp(int f){
	long long s=1;
	for(int i=0;i<f;i++) s=s*2;
	return s;
}
long long yu(){
	bool p1[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	bool p2[31]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int l1=0,l2;
	long long t=m[1];
	while(t>0){
		p1[30-l1]=t%2;
		
		t=t/2;
		l1++;
	}
	for(int i=2;i<=k;i++){
		t=m[i];
		l2=0;
		while(t>0){
			p2[30-l2]=t%2;
			t=t/2;
			l2++;
		}
		for(;l2<31;l2++){
			p2[30-l2]=0;
		}
		for(int i=0;i<31;i++){
			p1[i]=(p1[i]&&p2[i]);
		}
	}
	long long f=0;
	for(int i=30;i>=0;i--){
		f=f+(int(p1[i])*sp(30-i));
	}
	return f;
}
int dfs(int i,int d){
	m[d]=a[i];
	if(d>=k){
		maxx=max(maxx,yu());
		return maxx;
	}
	else{
		for(int j=i+1;j<=n;j++){
			dfs(j,d+1);
		}
	}
	return maxx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	if(!(cin>>n>>k)) return 0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-k+1;i++){
		dfs(i,1);
	}
	cout<<maxx;
	fclose(stdout);
	return 0;
}
