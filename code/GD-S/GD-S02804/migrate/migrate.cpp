#include<bits/stdc++.h>
using namespace std;
long long n,m,q[4000010],o,p,ma,c,z,v;
long long dd(long long l,long long r,long long ans){
	if(l==r){
		if(ma==-99999999){
			ma=max(ma,ans);
			p+=1;
		}
		else{
			if(ans==ma){
				p+=1;
				if(p>2){
					return 0;
				}
			}
		}
		return 0;
	}
	
	for(int i=r;i>=l+1;i--){
		if(q[i]-q[l]<=m){
			if(p>2){
				return 0;
			}
			dd(i,r,ans+1);
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>z>>v;
	for(int z1=1;z1<=v;z1++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>q[i];
		}
		if(m==1){
			cout<<0;
			continue;
		}
		o=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(q[j]-q[i]>m){
					ma=-99999999;
					p=0;
					
					dd(i,j,0);
					if(p==2){
						o+=1;	
					}
				}
			}
		}
		cout<<o<<"\n";
	}
	
	return 0;
} 
