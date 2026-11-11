#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,f[100005],ans=0;
int ha[100005];
int mild(int j){
	for(int i=1;i<=n;i++){
		if(j>=f[i]&&j<f[i+1]) return i;
	}
}
int ss(int q,int p){
	for(int i=q+1;i<=n;i++){
		if(f[i]-q<=d&&q+d<f[i+1]||i==n){
			ha[i]++;
			if(i!=n){
			 ss(f[i],2);
			for(int j=i-1;j>=1;j--){
				if(f[j]!=1&&p!=2){
				if(mild(f[i]+d)==mild(f[j]+d)||f[j]+2*d>=f[n]){
					ha[j]++;
					if(f[j]+2*d<f[n]) ss(f[j],2);
				}}
			}}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
		    cin>>f[i];
			ha[i]=-1;
			}
		ss(1,1);
		for(int i=1;i<=n;i++){
			if(ha[i]!=-1){
				ans+=ha[i];
			}
			}		
	cout<<ans<<" ";	
	} 
	return 0;
}
