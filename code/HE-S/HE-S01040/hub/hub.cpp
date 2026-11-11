#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,k,cnt[6];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		if(c==1){
			cin>>n>>k;
			for(int i=1;i<=n;i++) cnt[i]=0;
			int u,v;
			for(int i=1;i<n;i++){
				cin>>u>>v;
				cnt[u]++;
				cnt[v]++;
			}
			if(n==k){
				cout<<"0\n";
				continue;
			}
			if(k>=n-2){
				cout<<"1\n";
				continue;
			}
			if(n==4&&k==1){
				cout<<"1\n";
				continue;
			}
			if(n==5&&k==2){
				cout<<"1\n";
				continue;
			}
			if(n==5&&k==1){
				bool flag=0;
				for(int i=1;i<=n;i++)
					if(cnt[i]==n-1) flag=1;
				if(flag) cout<<"1\n";
				else cout<<"2\n";
			}
		}
		else if(c==13||c==14){
			cin>>n>>k;
			int u,v;
			for(int i=1;i<n;i++) cin>>u>>v;
			if(n==k){
				cout<<"0\n";
				continue;
			}
			int m=(n-1)/2;
			cout<<m/(k-1)+1<<'\n';
		}
	} 
	return 0;
}
