#include<bits/stdc++.h>
using namespace std;
int n,m;
struct item {
	int e;
	int choice;
}c[10000];
void solve(){
	bool flag=true;
	while(m--){
		for(int i=0;i<n;i++){
			cin>>c[i].e;
		}
		int ans=0,cnt[10000];
		if(c[i].choice==flag){
			cnt[i]++;
			c[i].e=cnt[i];
		}
		for(int i=1;i<=n;i++){           
			for(int j=i+1;j<=n;j++){
			if(c[i].e==c[j].e){
				ans+=2;
				i=j+1;
				j=i+1;
			}	
		}		
	}
	if(m==0) break;		
}	
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[100010],ans;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	solve();
	cout<<ans<<endl;
	return 0;
}
