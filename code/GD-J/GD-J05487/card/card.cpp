#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int z;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	int sum[m]{};
	int q[m];
	int _=0;
	int l=0,r=1;
	for(int i=0;i<n;i++){
		for(int j=l;j<r;j++){
			if(a[j]==1){
				q[_]=i;	
				
			}
		}
		if(a[l]==a[r]){
			l=r;
			r++;
		}else r++;
	}
	int o=1;
	for(int i=0;i<m;i++){
			cout<<q[i]<<" ";
			o++;
			i=0;
	 	
	}
	return 0;
}
