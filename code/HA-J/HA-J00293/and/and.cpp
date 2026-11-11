#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int n,m,ans=INT_MAX;
vector<int>b[32];
signed main(){
	fre("and");
	cin>>n>>m;
	int a[n];
	for(int&i:a)cin>>i;
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++)if(1&(a[i]>>j))b[j].push_back(i);
	}
	for(int i=31;i>=0&&m>0;i--){
		if(b[i].size()>=m)for(int j:b[i]){
			if(m<=0)break;
			if(a[j]==-1)continue;
			ans&=a[j];
			m--;
			a[j]=-1;
		}
	}
	
	cout<<ans;
	return 0;
}


