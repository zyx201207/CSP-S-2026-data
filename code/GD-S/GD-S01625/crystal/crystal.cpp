#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long v[500005],qz[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	qz[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
//		v[i]+=1e12+1;
	}
	sort(v+1,v+n+1);
	qz[1]=v[1];
	for(int i=2;i<=n;i++){
		qz[i]=qz[i-1]+v[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<v[i]<<' '<<qz[i]<<endl;
//	}
	int l=1,r=1,ans=1;
	while(r<=n){
		if( (v[r] * (r-l+1) ) - (qz[r]-qz[l-1]) > m){
			l++;
		}
		else{
			ans=max(ans,r-l+1);
//			cout<<l<<' '<<r<<' '<<ans<<endl;
			r++;
		}
//		cout<<'#';
	}
	
	cout<<ans;
} 

