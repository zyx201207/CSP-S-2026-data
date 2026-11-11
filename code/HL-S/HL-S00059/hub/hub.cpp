#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		cin>>n>>k;
		for(int j = 1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
		int minn = 1e9,minn2 = 1e9,minn3 = 1e9,minn4 = 1e9;
		for(int j = 1;j<=n;j++){
			if(minn>=u[j]){
				minn2 = minn;
				minn = u[j];
			
			}
			if(minn3<=v[j]){
				minn4 = minn3;
				minn3 = v[j];
			}
		}
		cout<<(minn+minn2)/2+(minn3+minn4)/2;
	}
	return 0;
}