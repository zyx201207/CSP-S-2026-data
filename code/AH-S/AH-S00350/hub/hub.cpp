#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,i,j,u,v,d,x,mi,l,r;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
		while(t--){
			cin>>n>>k;
			m=n/2;
			for(i=1;i<n;i++)cin>>u>>v;
			if(k>=n){cout<<"0\n";continue;}
			l=1;mi=r=n;
			while(l<=r){
				d=(l+r)/2;
				if(d+(d*2-1)*(k-1)+d>m){mi=min(mi,d);l=d+1;}
				else r=d-1;
			}
			cout<<mi<<"\n";
		}
}
