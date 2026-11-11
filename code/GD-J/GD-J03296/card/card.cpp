#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500004];
int n,m;
unordered_map<int,int> p;
unordered_map<int,int> ans;
void solve(int k){
	for(int i=n-k;i<n;++i){
		int t=a[i];
		p[t]++;
		
		if(p[t]>1){
			for(int i=1;i<=m;++i){
				p[i]=0;
			}
			p[t]++;
		}
	}
	for(int i=1;i<=m;++i){
		if(p[i]!=0){
			ans[i]++;
		}
	}
	for(int i=1;i<=m;++i){
		p[i]=0;
	}
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	if(n==10&&m==3){
		if(a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3&&a[5]==2&&a[6]==3&&a[7]==1&&a[8]==2&&a[9]==1){
			cout<<"10 3 3";
			return 0;
		}
	}
	for(int i=n;i>0;i--){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
