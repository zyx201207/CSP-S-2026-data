#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[300005];
long long a[500005];
map<long long,long long>cx;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cx[a[i]]=i;
	}for(int i=1;i<=n;i++){
		for(auto o:cx){
			if(o.second>=i)
				ans[o.first]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
