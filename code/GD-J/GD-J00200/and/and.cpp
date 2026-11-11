#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool b[200005][35],f[200005];
int max_w=0,yuan[200005];
void con(int n,int i){
	int t=0;
	while(n){
		b[i][t++]=n%2;
		n>>=1;
	}
	max_w=max(max_w,t);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		con(q,i);
		yuan[i]=q;
	}
	for(int i=max_w-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]==1) continue;
			if(b[j][i]) cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(f[j]==1) continue;
				if(!b[j][i]) f[j]=1;
			}
		}
	}
	ll k=0,ans=pow(2,32)-1;
	for(int i=1;i<=n&&k<=m;i++){
		if(f[i]==0){
			ans&=yuan[i];
			k++;
		}
	}
	cout<<ans;
	return 0;
}

