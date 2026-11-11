#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int M=1e5+1;
ll a[M];
ll st[M][1000];
ll qian[M][1000];
void build(){
	for(int i=1;i<=n;i++){
	for(int k=1;k<=n;k++){
			for(int j=i;j<i+k;j++){
				st[i][k]=max(st[i][k],a[j]);
			}
}}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;

memset(st,0,sizeof(st));
memset(qian,0,sizeof(qian));
for(int i=1;i<=n;i++){
	cin>>a[i];
	st[i][0]=a[i];
}
build();
ll ans=-0x3f3f3f3f3f3f3f3f;
for(int i=1;i<=n;i++){
	for(int k=1;k<=n;k++){
			for(int j=i;j<i+k;j++){
				qian[i][k]+=a[j];
			}
}}
		for(int i=1;i<=n;i++){
	for(int k=1;k<=n;k++){
			if((k*st[i][k]-st[i][k]-qian[i][k-1])==m){
			if(ans<=k*st[i][k]) ans=k;
		
}}}
		cout<<ans;
} 
