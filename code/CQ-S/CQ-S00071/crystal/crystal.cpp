#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int a[N];

deque<int> q;

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,m;
	cin>>n>>m;
	
	for (int i=1;i<=n;i++) cin>>a[i]; 
		
	sort(a+1,a+1+n);
		
	int sum=0;
	int siz=0,ans=0;
		
	for (int i=1;i<=n;i++){
			
		q.push_back(a[i]);
		sum+=a[i]; siz++; 
				
		while (!q.empty()&&siz*q.back()-sum>m) 
			{sum-=q.front(); q.pop_front(); siz--; }
				
		ans=max(ans,siz);
		
	}
		
	cout<<ans;
	
	return 0;

} 

//Oct31==Dec25?
