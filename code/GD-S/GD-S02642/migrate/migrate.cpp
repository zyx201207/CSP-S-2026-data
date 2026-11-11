#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int c,t,n,ans;
long long num,d,x[2000005],s[2000005],mn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0,mn=1e9;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=s[i-1]+x[i];
			if(i!=1) mn=min(mn,x[i]-x[i-1]);
		} 
		if(d<mn){
			cout<<0<<'\n';
			continue;
		} 
		for(int len=4;len<=n;len+=2){
			for(int l=1;l<=n-len+1;l++){
			num=s[l+len-1]-2*s[l+len/2-1]+s[l-1];
			if(x[l+len-1]-x[l]<=2*d&&num==len/2*d) ans++;
		}
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}

