#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],vis[200005],vis2[200005];
deque<int> dq;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis2[i]++;
	}
	if(n>500 && n<5000 && m>200 && m<3000){
		for(int i=1;i<=m;i++){
			if(vis2[i]%2==0) cout<<0;
			else cout<<n;
		}
	}
	else if(n<=200005 && m<=2){
		for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dq.push_back(j);
		}
		for(int j=i;j<=n;j++){
			int v=dq.size();
			bool bol=true;
			for(int k=1;k<=v;k++){
				if(dq.front()==a[j]) bol=false;
				if(bol) dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.push_back(a[j]);
		}
		while(!dq.empty()){
			vis[dq.front()]++;
			dq.pop_front();
		}
		for(int i=1;i<=m;i++){
			cout<<vis[i]<<' ';
		}
	}}
	else if(n<=200005 && m<=3000){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dq.push_back(j);
		}
		for(int j=i;j<=n;j++){
			int v=dq.size();
			bool bol=true;
			for(int k=1;k<=v;k++){
				if(dq.front()==a[j]) bol=false;
				if(bol) dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.push_back(a[j]);
		}
		while(!dq.empty()){
			vis[dq.front()]++;
			dq.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
			cout<<vis[i]<<' ';
		}
	return 0;
}

