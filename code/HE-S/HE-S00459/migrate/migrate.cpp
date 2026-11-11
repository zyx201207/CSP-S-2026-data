#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int c;
	cin>>c;
	c=919178;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<int>dc;
		for(int i=1;i+3<=n;i++){
			if(a[i+2]-a[i]<=d && a[i+3]-a[i+1]<=d && a[i+3]-a[i]>d)dc.push_back(i);
		}
		int sum=0;
		for(int i=0;i<dc.size();i++){
			int j=dc[i]-1;
			while(j>0 && a[j+2]-a[j]>d && a[j+1]-a[j]<=d)j--;
			int k=dc[i]+4;
			while(k<=n && a[k]-a[k-2]>d && a[k]-a[k-1]<=d)k++;
			sum+=(dc[i]-(j))*((k)-(dc[i]+3));
		}
		cout<<sum<<endl;
	}
	return 0;
}
