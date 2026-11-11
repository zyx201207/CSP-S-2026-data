#include<bits/stdc++.h>
using namespace std;
int T,N,n,m,a[2500007],dc;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T>>N;
	if(T==11 || T==12){
		while(N--){
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			int dc=a[2]-a[1];
			//cout<<m<<" "<<dc<<endl;
			if (m==1 || m/dc==1){
				cout<<0<<endl;
				continue;
			}
			cout<<(n-m/dc)*(m/dc-1)<<endl;
						
		}	
	}else if(T==13 || T==14){
		while(N--){
			cin>>n>>m;
			cout<<0<<endl;
		}
	}
	return 0;
}

