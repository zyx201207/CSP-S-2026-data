#include<bits/stdc++.h>
using namespace std; 
int n,m,a[200005];
vector<int> tmp,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		b.push_back(a[i]);
	} 
	int ans=0;
	for(int i=29;i>=0;i--){
		tmp.clear();
		for(int j=0;j<(int)b.size();j++){
			if((b[j]>>i)&1){
				tmp.push_back(b[j]);
			}
		}
		if((int)tmp.size()>=m){
			b=tmp;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
