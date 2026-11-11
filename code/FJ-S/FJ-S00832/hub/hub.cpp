#include<bits/stdc++.h>
using namespace std;
int c,n,t,m,x,y;
//vector<int>ve[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
		//	ve[x].push_back(y);
			//ve[y].push_back(x);
		}
		if(m==1){
			cout<<(n-1)/2;
		}else{
			int k=(n+1)/2;
			if(k%2==1){
				m-=1;
				
				int p=k/2;
				if(p%2==0){
					m-=2;
				}
				
				cout<<p/2-(m/4);
			}else{
				int p=k/2;
				if(p%2==0){
					m-=2;
				}
				cout<<p/2-(m/4);
			}
		}
	}
	return 0;
}
