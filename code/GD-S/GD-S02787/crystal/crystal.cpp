#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int b[N];
vector<int>v;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	int d=0;
	//int mx=-1e18;
	int mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
		d+=a[i];
		
	}
	sort(v.begin(),v.end());
	sort(a+1,a+n+1);
	int mx=v.back();
	//cout<<v[0];
	int ans=-1e9;
	int k=(n+1ll)/2;
	int x=a[1];
	int cnt=1;
	while(m){
		for(int i=1;i<=n;i++){
			if(m>=x-a[i]&&x>=a[i]){
				m-=(x-a[i]);
				a[i]=x;
				
			}
		} 
		x++;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt++;
		
	}	
	
	cout<<cnt;
	return 0;
}
