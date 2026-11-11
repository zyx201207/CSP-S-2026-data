#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<int>ans(m,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector<int>b;
		for(int j=i;j<n;j++){
			if(find(b.begin(),b.end(),a[j])!=b.end()){
				b.erase(find(b.begin(),b.end(),a[j]),b.end());
			}
			b.push_back(a[j]);
			
		}
		for(int j=0;j<b.size();j++){
			ans[b[j]]++;
		}
		
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
