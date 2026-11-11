#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,s[300005],c[30005];
vector<int> b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=n;w>=1;w--){
		if(s[a[w]]!=0){
			for(auto x:b[s[a[w]]]){
				b[w].push_back(x);
			}
		}else{
			s[a[w]]=w;
			b[w].push_back(a[w]);
			for(auto x:b[w+1]){
				b[w].push_back(x);
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(auto x:b[i]){
			c[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
