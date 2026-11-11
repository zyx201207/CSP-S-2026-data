#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	vector<int> ar;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;cin>>a;ar.push_back(a);
	}
	int ans=-1e9;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
					ans=max(ans,((ar[i]&ar[j])&ar[k]));
			}
		}
	
	cout<<ans;
	return 0;
} 
