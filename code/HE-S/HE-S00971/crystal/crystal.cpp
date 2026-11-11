#include<bits/stdc++.h>
using namespace std;
struct p{
	long long l;
};
struct o{
	int s,z;
};
bool q(p x,p y){
	return x.l<y.l;
}
o dp[500005][500005];
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout"); 
	p n,m;
	cin>>n.l>>m.l;
	p b[n.l];
	for(int i=0;i<n.l;i++){
		cin>>b[i].l;
	}
	sort(b,b+n.l,q);
	for(int i=0;i<n.l;i++){
		dp[i][i].s=1;
		dp[i][i].z=0;
	}
	for(int i=n.l-2;i>=0;i--){
		for(int j=i+1;j<n.l;j++){
			int u=dp[i+1][j].s,v=1,k=dp[i+1][j].z,h=0;
			if(b[j].l-b[i].l<=m.l-dp[i+1][j].z){
				u=u+1;
				k=k+b[j].l-b[i].l;
			}
			v=v+min(dp[i][j-1].s,int((m.l-dp[i][j-1].z)/(b[j].l-b[j-1].l)));
			if(v!=1)h=(v-1)*(b[j].l-b[j-1].l)+dp[j-v+1][j-1].z;
			if(u>v){
				dp[i][j].s=u;
				dp[i][j].z=k;
			}
			else if(u<v){
				dp[i][j].s=v;
				dp[i][j].z=h;
			}
			else{
				dp[i][j].s=u;
				dp[i][j].z=min(k,h);
			}
		}
	}
	int t=0;
	for(int i=0;i<n.l;i++){
		for(int j=0;j<n.l;j++){
			t=max(t,dp[i][j].s);
		}
	}
	cout<<t;
	return 0;
} 
