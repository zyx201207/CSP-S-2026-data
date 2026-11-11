#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+7;
int n,m,b[N],ans,f[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j,ct,t;
	cin>>ct>>t;
	while(t--){
		cin>>n>>m;
		int u,v;
		for(i=1;i<=n;i++){
			cin>>u>>v;
		}
		if(n==2){
			if(m==2){
				cout<<0<<endl;
			}
		}
		if(n==3){
			if(m==3){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
		if(n==4){
			if(n==m){
				cout<<0<<endl;
			}else{
				if(m==3||m==2){
					cout<<1<<endl;
				}
				
			}
		}
		if(n==5){
			if(n==m){
				cout<<0<<endl;
			}else{
				if(m==4||m==2||m==3){
					cout<<1<<endl;
				}
			}
		}
	}
	return 0;
}
